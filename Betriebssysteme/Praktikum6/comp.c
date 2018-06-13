#include "miniz.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <pthread.h>
#include "comp.h"
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
	time_t start;
	time(&start);
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
	ThreadManager manager = createThreadManager();

	/*start dir content reading thread*/
	setReadingThread(&manager, 1);
	
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
		int currentThreads = getActiveThreads(&manager);
		int readThread = getReadingThreads(&manager);
		
		pthread_mutex_lock(queue.mutex);
		int empty = queue_empty(queue.queue);
		pthread_mutex_unlock(queue.mutex);
		
		if (!empty && currentThreads < maxThreads) {
			/*If queue is not empty and there are free threads left*/
			pthread_mutex_lock(queue.mutex);
			job *head = queue_head(queue.queue);
			queue_delete(queue.queue);
			pthread_mutex_unlock(queue.mutex);
			
			compThreadArgs *comprArgs = (compThreadArgs *)malloc(sizeof(compThreadArgs));
			comprArgs->currentJob = head;
			comprArgs->id = id;
			comprArgs->manager = &manager;
			
			incActiveThreads(&manager);
			
			pthread_t compThread;
			if (pthread_create(&compThread, NULL, comprFile, comprArgs)) {
				perror("Thread not started: ");
			}
			id++;
		} else if (empty && !readThread) {
			/*If queue is empty and reading Thread is not reading end loop*/
			running = 0;
		} else {
			/*Wait for free thread*/
			waitForThreads(&manager, maxThreads - 1);
		}
	}
	
	waitForThreads(&manager, 0);	
	
	deleteManager(&manager);
	
	
	time_t end;
	time(&end);
	double diff = difftime(end, start);
	printf("Laufzeit: %f\nThreads: %d\n", diff, maxThreads);
	return EXIT_SUCCESS;
}

void *readFiles(void *args) {
	DIR *dir = ((threadArgs *)args)->dir;
	char *path = ((threadArgs *)args)->path;
	Mutex_Queue *queue = ((threadArgs *)args)->queue;
	ThreadManager *manager = ((threadArgs *)args)->manager;
	readDir(dir, queue, path);
	
	setReadingThread(manager, 0);
	return args;
}

void readDir(DIR *dir, Mutex_Queue *queue, char *path) {
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
				if (sleepTime) {
					sleep(1);
				}
			}
		} else if (strcmp (file->d_name, ".") && strcmp (file->d_name, "..") && file->d_type == DT_DIR){
			char realname[sizeof(path) + sizeof(file->d_name) + 2];
			realname[0] = '\0';
			strcat(realname, path);
			char *divider = "/\0";
			strcat(realname, divider);
			strcat(realname, file->d_name);
			realname[sizeof(realname) - 1] = '\0';
			DIR *newdir = opendir(realname);
			if (newdir) {
				readDir(newdir, queue, realname);
			}
		}
	}
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
	strcat(newName, currentJob->name); 
	pthread_mutex_unlock(currentJob->mutex);
	
	strcat(newName, compressedEnding);
	FILE *newFile = fopen(newName, "w");
	
	if (newFile) {
		pthread_mutex_lock(currentJob->mutex);
		
		for(int i = 0; i < sizeof(comprResult->data); i++) {
			fputc(comprResult->data[i], newFile);
		}
		fclose(newFile);
		
		pthread_mutex_unlock(currentJob->mutex);
	}
	if (sleepTime) {
		sleep(3);
	}
	
	free(comprResult->data);
	free(comprResult);
	deleteJob(currentJob);
	
	decActiveThreads(manager);
	
	free(args);
	
	return NULL;
}



	
