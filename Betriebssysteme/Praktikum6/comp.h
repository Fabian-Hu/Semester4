#include "queue.h"
#include <dirent.h>

typedef struct threadManager {
	pthread_mutex_t *mutex;
	pthread_cond_t *cond;
	int activeThreads;
	int readingThread;
} ThreadManager;

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


const unsigned int maxThreads = 5;
const char *compressedEnding = ".compr";

void deleteJob(job *deleteJob);

void *readFiles(void *arg);

void getFileContent(job *dest, const char *filename);

void *comprFile(void *arg);
