#include <stdio.h>
//#include "miniz.h"
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
	int done;
} Job;
Job daten;

Job *data = &daten;

char dir[256];

int add(char* file,Job*daten){
	
	queue_insert(daten->queue,(void*)file);
	return 0;
}
char* get_head(Job*daten){
	char* value = (char*) daten->queue->head->value;
	queue_delete(daten->queue);
	return value;
}

void * lock(Job* daten){	
	pthread_mutex_lock(daten->mutex);
	int temp = daten->sync;
	while(temp){
		pthread_cond_wait (daten->cond, daten->mutex);
	}
	daten->sync = 1;
}

void *unlock(void* args){
	Job* daten = (Job*) args;
	daten->sync = 0;
	pthread_mutex_unlock(daten->mutex);
	pthread_cond_broadcast(daten->cond);
}

void *get_files(void *args){	
	printf("Dateien werden gelesen %s.\n",dir);
	Job* daten = (Job*) args;
	struct dirent *de; // Pointer auf den aktuellen Ort
    DIR *dr = opendir(dir); // Der Ordner wird geöffnet
    if (dr == NULL) {
        printf("Der Ordner kann nicht geoeffnet werden.\n" );
        return (void*)NULL;
    }
    long length;
    char * buffer = 0;
    char result[256];
    FILE * file;
    while ((de = readdir(dr)) != NULL){ // es wird solange gelesen, wie es dateien gibt.
		
        if(!strstr(de->d_name,".compr") // .compr wird ignoriert
        && !strcmp(de->d_name,"..")==0 // .. wird ignoriert
        && !strcmp(de->d_name,".")==0 // 8 == Datei, 4 == Ordner
        && de->d_type == 8){ // . wird ignoriert
			lock(daten);
            printf("Neu: %s\n", de->d_name);
            memset(result, 0, sizeof(result));
			strcpy(result,dir);
            strcat(result,de->d_name);
            file = fopen(result,"r");
            fseek(file,0,SEEK_END);
            length = ftell(file);
            buffer = (char*)malloc(sizeof(char)*length);
            if(buffer){
				fread(buffer,sizeof(char)*length,1,file);
				printf("Datei gelesen: \n");
			}
			
			sleep(1);
			
			
			fclose(file);
 ;          add(buffer,daten);
            unlock(daten);
		}
		
	}
	printf("\nDateien fertig gelesen\n");
	daten->done = 1;
    closedir(dr);    
	return (void*)NULL;
}


void *compress(void* args){
	Job * daten = (Job*) args;
	printf("Neuer Prozess\n");
	while(queue_empty(daten->queue) && !daten->done);
	while(!queue_empty(daten->queue)){ // kein null wert
		lock(daten);
		char * string = get_head(daten);
		printf("Komprimiert: \n");
		//Result *result = compress_string(string);
		// <=hier muss komprimiert werden
		// wenn fertig
		unlock(daten);
		
		sleep(3);
		
	}	
}

void create_threads(void*args,int count){ // anzahl threads variable
	pthread_t reader;
	pthread_t comp;
	pthread_t comp2;
	pthread_t comp3;
	pthread_t *test[count];
	
	int x =0;
	int status1 = 0;
	int status2 = 0;
	int status3 = 0;
	int status4 = 0;
	printf("Threads werden erstellt.\n");
	//mutex
	Job *daten = (Job*)args;
	daten->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(daten->mutex, NULL);
	daten->cond = (pthread_cond_t *)malloc(sizeof(pthread_cond_t));
	pthread_cond_init(daten->cond,NULL);
	// der reader
	status1 = pthread_create(&reader, NULL, get_files, args);
	
	for(int i =0;i<count;i++){
		test[i] = (pthread_t*) malloc(sizeof(pthread_t));
		pthread_create(test[i], NULL, compress, args);
	}
	
	pthread_join(reader,NULL);
	for(int i = 0;i<count;i++){
		pthread_join(*test[i],NULL);
	}
		
}

void main(int argc,char ** argv){
	time_t start;
	time(&start);
	system("clear");
	strcpy(dir,argv[1]);
	data->queue = queue_create();
	data->sync = 0;
	data->done = 0;
	create_threads(data,1);
	queue_destroy(data->queue);// am ende alles freigeben
	pthread_mutex_destroy(data->mutex);
	
	time_t end;
	time(&end);
	double diff = difftime(end, start);
	printf("Laufzeit: %f\nThreads: %d\n", diff, 3);
}
