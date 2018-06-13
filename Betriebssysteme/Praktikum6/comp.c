#include "miniz.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <pthread.h>
#include "comp.h"
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	/*check if dirame is given*/
	if (argc != 2) {
		return EXIT_FAILURE;
	}
	char realname[128];
	realpath(argv[1], realname);
	
	/*check if dir exists*/
	DIR *dir = opendir(realname);
	if (!dir) {
		return EXIT_FAILURE;
	}

	/*Init Queue*/
	Mutex_Queue queue;
	queue.queue = queue_create();
	queue.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(queue.mutex, NULL);
	
	/*Init Thread Manager*/
	ThreadManager manager;
	manager.activeThreads = 0;
	manager.readingThread = 0;
	manager.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(manager.mutex, NULL);
	manager.cond = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	pthread_cond_init(manager.cond, NULL);
	
	/*start dir content reading thread*/
	pthread_mutex_lock(manager.mutex);
	manager.readingThread = 1;
	pthread_mutex_unlock(manager.mutex);
	
	threadArgs args = {dir, realname, &queue, &manager};
	pthread_t readFileThread;
	if (pthread_create(&readFileThread, NULL, readFiles, &args)) {
		perror("Thread not started: ");
		return EXIT_FAILURE;
	}	
	
	/*Start compr threads*/
	int id = 0;
	int running = 1;
	while(running) {		
		pthread_mutex_lock(manager.mutex);
		int currentThreads = manager.activeThreads;
		int readThread = manager.readingThread;
		pthread_mutex_unlock(manager.mutex);
		
		pthread_mutex_lock(queue.mutex);
		int empty = queue_empty(queue.queue);
		pthread_mutex_unlock(queue.mutex);
		
		if (!empty && currentThreads < maxThreads) {
			pthread_mutex_lock(queue.mutex);
			job *head = queue_head(queue.queue);
			queue_delete(queue.queue);
			pthread_mutex_unlock(queue.mutex);
			
			printf("Job %s\n", head->name);
			
			compThreadArgs *comprArgs = (compThreadArgs *)malloc(sizeof(compThreadArgs));
			comprArgs->currentJob = head;
			comprArgs->id = id;
			comprArgs->manager = &manager;
			
			pthread_mutex_lock(manager.mutex);
			manager.activeThreads++;
			pthread_mutex_unlock(manager.mutex);
			
			pthread_t compThread;
			if (pthread_create(&compThread, NULL, comprFile, comprArgs)) {
				perror("Thread not started: ");
			}
			id++;
		} else if (empty && !readThread) {
			running = 0;
		} else {
			pthread_mutex_lock(manager.mutex);
			while(manager.activeThreads >= maxThreads) {
				pthread_cond_wait(manager.cond, manager.mutex);
			}
			pthread_mutex_unlock(manager.mutex);
		}
	}
	
	pthread_mutex_lock(manager.mutex);
	while(manager.activeThreads) {
		pthread_cond_wait(manager.cond, manager.mutex);
	}
	pthread_mutex_unlock(manager.mutex);
	
	printf("%d\n", manager.activeThreads);
	//Queue und Manager freen
	return EXIT_SUCCESS;
}

void *readFiles(void *args) {
	DIR *dir = ((threadArgs *)args)->dir;
	char *path = ((threadArgs *)args)->path;
	Mutex_Queue *queue = ((threadArgs *)args)->queue;
	ThreadManager *manager = ((threadArgs *)args)->manager;
	struct dirent *file;
	
	while (file = readdir(dir)) {
		if (strcmp (file->d_name, ".") && strcmp (file->d_name, "..") && file->d_type != DT_DIR && !strstr(file->d_name, compressedEnding)) {
			job *newJob = (job *)malloc(sizeof(job));
			if (newJob) {	
				newJob->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
				pthread_mutex_init(newJob->mutex, NULL);
	
				char realname[sizeof(path) + sizeof(file->d_name) + 2];
				realname[0] = '\0';
				strcat(realname, path);
				char *divider = "/\0";
				strcat(realname, divider);
				strcat(realname, file->d_name);
				realname[sizeof(realname) - 1] = '\0';
				
				pthread_mutex_lock(newJob->mutex);
				newJob->name = (char *)malloc(sizeof(realname));
				if (newJob->name) {
					strcpy(newJob->name, realname);
				}
				pthread_mutex_unlock(newJob->mutex);
				
				getFileContent(newJob, realname);
				pthread_mutex_lock(queue->mutex);
				queue_insert(queue->queue, newJob);
				pthread_mutex_unlock(queue->mutex);
			}
		}
	}
	
	pthread_mutex_lock(manager->mutex);
	manager->readingThread = 0;
	pthread_mutex_unlock(manager->mutex);
	return args;
}

void deleteJob(job *deleteJob) {
	pthread_mutex_lock(deleteJob->mutex);
	free(deleteJob->name);
	free(deleteJob->content);
	pthread_mutex_unlock(deleteJob->mutex);
	
	pthread_mutex_destroy(deleteJob->mutex);
	
	free(deleteJob->mutex);
	free(deleteJob);
	deleteJob = NULL;
}


void getFileContent(job *dest, const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file) {
		struct stat stats;
		fstat(fileno(file), &stats);
		off_t size = stats.st_size;
		pthread_mutex_lock(dest->mutex);
		dest->content = (char *)malloc(size);
		
		if (dest) {
			char c;
			int index = 0;
			while ((c = fgetc(file)) != EOF) {
				dest->content[index] = c;
				index++;
			}
		}
		pthread_mutex_unlock(dest->mutex);
		fclose(file);
	}
}

void *comprFile(void *args) {
	job *currentJob = ((compThreadArgs *)args)->currentJob;
	ThreadManager *manager = ((compThreadArgs *)args)->manager;
	
	pthread_mutex_unlock(currentJob->mutex);
	Result *comprResult = compress_string(currentJob->content);
	pthread_mutex_unlock(currentJob->mutex);

	char newName[strlen(currentJob->name) + sizeof(compressedEnding) + 1];
	newName[0] = '\0';
	
	pthread_mutex_lock(currentJob->mutex);
	strcat(newName, currentJob->name); //<- FEHLER!!!!!
	pthread_mutex_unlock(currentJob->mutex);
	
	strcat(newName, compressedEnding);
	printf("Hello: %s\n", newName);
	FILE *newFile = fopen(newName, "w");
	
	if (newFile) {
		pthread_mutex_lock(currentJob->mutex);
		
		for(int i = 0; i < sizeof(comprResult->data); i++) {
			fputc(comprResult->data[i], newFile);
		}
		fclose(newFile);
		
		pthread_mutex_unlock(currentJob->mutex);
	}
	
	free(comprResult->data);
	free(comprResult);
	deleteJob(currentJob);
	
	pthread_mutex_lock(manager->mutex);
	manager->activeThreads--;
	pthread_mutex_unlock(manager->mutex);
	pthread_cond_signal(manager->cond);
	
	free(args);
	return NULL;
}



	
