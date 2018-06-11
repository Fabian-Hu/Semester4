#include "queue.h"
#include <dirent.h>

typedef struct Mutex_Queue {
	pthread_mutex_t *mutext;
	Queue queue;
} Mutex_Queue;

typedef struct threadArgs {
	DIR *dir;
	char *path;
	Queue queue;
	int *running;
} threadArgs;

typedef struct job {
	char *name;
	char *content;
} job;

typedef struct compThreadArgs {
	job *currentJob;
	int id;
} compThreadArgs;

const unsigned int threads_num = 5;
const char *compressedEnding = ".compr";

void deleteJob(job *deleteJob);

void *readFiles(void *arg);

void getFileContent(job *dest, const char *filename);

void *comprFile(void *arg);
