#include "threadManager.h"
#include <stdlib.h>

ThreadManager createThreadManager() {
	ThreadManager manager;
	manager.activeThreads = 0;
	manager.readingThread = 0;
	manager.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(manager.mutex, NULL);
	manager.cond = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	pthread_cond_init(manager.cond, NULL);
	return manager;
}

void setReadingThread(ThreadManager *manager, int val) {
	pthread_mutex_lock(manager->mutex);
	manager->readingThread = val;
	pthread_mutex_unlock(manager->mutex);
}

int getActiveThreads(ThreadManager *manager) {
	pthread_mutex_lock(manager->mutex);
	int currentThreads = manager->activeThreads;
	pthread_mutex_unlock(manager->mutex);
	return currentThreads;
}

int getReadingThreads(ThreadManager *manager) {
	pthread_mutex_lock(manager->mutex);
	int readThread = manager->readingThread;
	pthread_mutex_unlock(manager->mutex);
	return readThread;
}

void incActiveThreads(ThreadManager *manager) {
	pthread_mutex_lock(manager->mutex);
	manager->activeThreads++;
	pthread_mutex_unlock(manager->mutex);
}

void decActiveThreads(ThreadManager *manager) {
	pthread_mutex_lock(manager->mutex);
	manager->activeThreads--;
	pthread_mutex_unlock(manager->mutex);
	pthread_cond_signal(manager->cond);
}

void waitForThreads(ThreadManager *manager, int maxThreads) {
	pthread_mutex_lock(manager->mutex);
	while(manager->activeThreads > maxThreads) {
		pthread_cond_wait(manager->cond, manager->mutex);
	}
	pthread_mutex_unlock(manager->mutex);
}

void deleteManager(ThreadManager *manager){
	pthread_cond_destroy(manager->cond);
	pthread_mutex_destroy(manager->mutex);
	
	free(manager->cond);
	free(manager->mutex);
}
