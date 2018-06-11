#include "miniz.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <pthread.h>
#include "comp.h"
#include <string.h>
#include <sys/stat.h>

int readThreadRunning = 0;
int currentNumberThreads = 0;

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
	
	Queue queue = queue_create();
	
	/*start dir content reading thread*/
	readThreadRunning = 1;
	threadArgs args = {dir, realname, queue, &readThreadRunning};
	pthread_t readFileThread;
	if (pthread_create(&readFileThread, NULL, readFiles, &args)) {
		perror("Thread not started: ");
		return EXIT_FAILURE;
	}
	
	int id = 0;
	int running = 1;
	while(running) {
		if (!queue_empty(queue)) {
			job *head = queue_head(queue
			printf("Job %s\n", head->name);
			queue_delete(queue);
			compThreadArgs comprArgs = {head, id};
			pthread_t compThread;
			if (pthread_create(&compThread, NULL, comprFile, &comprArgs)) {
				perror("Thread not started: ");
			}
			currentNumberThreads++;
			id++;
		} else if (queue_empty(queue) && !readThreadRunning) {
			running = 0;
		}
	}
	pthread_join(readFileThread, (void **)&args);
	
	printf("%d\n", currentNumberThreads);
	while(currentNumberThreads);
	
	return EXIT_SUCCESS;
}

void *readFiles(void *args) {
	DIR *dir = ((threadArgs *)args)->dir;
	char *path = ((threadArgs *)args)->path;
	Queue queue = ((threadArgs *)args)->queue;
	int *running = ((threadArgs *)args)->running;
	*running = 1;
	struct dirent *file;
	
	while (file = readdir(dir)) {
		if (strcmp (file->d_name, ".") && strcmp (file->d_name, "..") && file->d_type != DT_DIR && !strstr(file->d_name, compressedEnding)) {
			job *newJob = malloc(sizeof(job));
			if (newJob) {	
				char realname[sizeof(path) + sizeof(file->d_name) + 1];
				realname[0] = '\0';
				strcat(realname, path);
				char *divider = "/\0";
				strcat(realname, divider);
				strcat(realname, file->d_name);
				newJob->name = malloc(sizeof(realname));
				if (newJob->name) {
					strcpy(newJob->name, realname);
				}
				getFileContent(newJob, realname);
				queue_insert(queue, newJob);
			}
		}
	}
	
	*running = 0;
	return args;
}

void deleteJob(job *deleteJob) {
		free(deleteJob->name);
		free(deleteJob->content);
		free(deleteJob);
		deleteJob = NULL;
}


void getFileContent(job *dest, const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file) {
		struct stat stats;
		fstat(fileno(file), &stats);
		off_t size = stats.st_size;
		dest->content = malloc(size);
		
		if (dest) {
			char c;
			int index = 0;
			while ((c = fgetc(file)) != EOF) {
				dest->content[index] = c;
				index++;
			}
		}
		fclose(file);
	}
}

void *comprFile(void *args) {
	job *currentJob = ((compThreadArgs *)args)->currentJob;
	printf("Hello: %s\n", currentJob->name);
	Result *comprResult = compress_string(currentJob->content);
	
	printf("Hello: %s\n", currentJob->name);
	FILE *newFile = fopen(currentJob->name, "w");
	if (newFile) {
		printf("newFile");
		fputs(comprResult->data, newFile);
		fclose(newFile);
	}
	
	free(comprResult->data);
	free(comprResult);
	deleteJob(currentJob);
	currentNumberThreads--;
	return currentJob;
}



	
