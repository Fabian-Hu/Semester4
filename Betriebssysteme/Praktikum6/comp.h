#include <dirent.h>
#include "threadManager.h"
#include "queue.h"

typedef struct Mutex_Queue {
	pthread_mutex_t *mutex;
	Queue queue;
} Mutex_Queue;

typedef struct threadArgs {
	DIR *dir;
	char *path;
	Mutex_Queue *queue;
	ThreadManager *manager;
} threadArgs;

typedef struct job {
	pthread_mutex_t *mutex;
	char *name;
	char *content;
} job;

typedef struct compThreadArgs {
	job *currentJob;
	int id;
	ThreadManager *manager;
} compThreadArgs;


const unsigned int maxThreads = 4;
const char *compressedEnding = ".compr";
const int sleepTime = 0;

void deleteJob(job *deleteJob);

void *readFiles(void *arg);

void getFileContent(job *dest, const char *filename);

void *comprFile(void *arg);
;
void readDir(DIR *dir, Mutex_Queue *queue, char *path);
