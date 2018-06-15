#include <stdio.h>
#include "miniz.h"
#include "queue.h"
#include <pthread.h>
#include <string.h>
#include <dirent.h>

typedef struct
{
	pthread_mutex_t *mutex;
	Queue queue;
	pthread_cond_t *cond;
	int sync;
} Daten;
Daten daten;

Daten *data = &daten;

char dir[256];

int add(char* file,Daten*daten){
	
	queue_insert(daten->queue,(void*)file);
	return 0;
}
char* get_head(Daten*daten){
	char* value = (char*)queue_head(daten->queue);
	queue_delete(daten->queue);
	return value;
}

void * lock(Daten* daten){	
	pthread_mutex_lock(daten->mutex);
	int temp = daten->sync;
	printf("%i",temp);
	printf("lock\n");
	while(temp){
		printf("while\n");
		pthread_cond_wait (daten->cond, daten->mutex);
	}
	daten->sync = 1;
}

void *unlock(void* args){
	Daten* daten = (Daten*) args;
	daten->sync = 0;
	printf("unlock\n");
	pthread_mutex_unlock(daten->mutex);
	pthread_cond_broadcast(daten->cond);
}

void *get_files(void *args){	
	printf("Dateien werden gelesen.\n");
	Daten* daten = (Daten*) args;
	struct dirent *de; // Pointer auf den aktuellen Ort
    DIR *dr = opendir(dir); // Der Ordner wird geöffnet
    if (dr == NULL) {
        printf("Der Ordner kann nicht geoeffnet werden.\n" );
        return (void*)NULL;
    }
    while ((de = readdir(dr)) != NULL){ // es wird solange gelesen, wie es dateien gibt.
		
        if(!strstr(de->d_name,".compr") // .compr wird ignoriert
        && !strcmp(de->d_name,"..")==0 // .. wird ignoriert
        && !strcmp(de->d_name,".")==0){ // . wird ignoriert
			lock(daten);
			//printf("%i\n",de->d_type); // 8 == Datei, 4 == Ordner
            printf("%s\n", de->d_name);
            add(de->d_name,daten);
            unlock(daten);
		}
	}
    closedir(dr);    
	return (void*)NULL;
}


void *compress(void* args){
	Daten * daten = (Daten*) args;
	printf("Neuer Prozess in Compress\n");
	while(queue_empty(daten->queue));
	printf("Daten sind da.\n");
	while(!queue_empty(daten->queue)){ // kein null wert
		printf("in der WHile");
		lock(daten);
		printf("Komprimiert: %s\n",get_head(daten));
		// <=hier muss komprimiert werden
		
		// wenn fertig
		unlock(daten);
	}
}

void create_threads(void*args){ // anzahl threads variable
	pthread_t reader;
	pthread_t comp;
	pthread_t comp2;
	pthread_t comp3;
	int x =0;
	int status1 = 0;
	int status2 = 0;
	int status3 = 0;
	int status4 = 0;
	printf("Threads werden erstellt.\n");
	//mutex
	Daten *daten = (Daten*)args;
	daten->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(daten->mutex, NULL);
	daten->cond = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	pthread_cond_init(daten->cond,NULL);
	// der reader
	status1 = pthread_create(&reader, NULL, get_files, args);
	//ein compressor
	status2 = pthread_create(&comp, NULL, compress, args);
	status3 = pthread_create(&comp2, NULL, compress, args);
	status4 = pthread_create(&comp3, NULL, compress, args);
	
	
	printf("Es geht weiter\n");
	pthread_join(reader,NULL);
	pthread_join(comp,NULL);
	pthread_join(comp2,NULL);
	pthread_join(comp3,NULL);
		
}

void main(int argc,char ** argv){
	system("clear");
	strcpy(dir,argv[1]);
	data->queue = queue_create();
	data->sync = 0;
	create_threads(data);
	queue_destroy(data->queue);// am ende alles freigeben
	pthread_mutex_destroy(data->mutex);
}
