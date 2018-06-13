#include <pthread.h>

typedef struct threadManager {
	pthread_mutex_t *mutex;
	pthread_cond_t *cond;
	int activeThreads;
	int readingThread;
} ThreadManager;

ThreadManager createThreadManager();

void setReadingThread(ThreadManager *manager, int val);

int getActiveThreads(ThreadManager *manager);

int getReadingThreads(ThreadManager *manager);

void incActiveThreads(ThreadManager *manager);

void decActiveThreads(ThreadManager *manager);

void waitForThreads(ThreadManager *manager, int maxThreads);

void deleteManager(ThreadManager *manager);
