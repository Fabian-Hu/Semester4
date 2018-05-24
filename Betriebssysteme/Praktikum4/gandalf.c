#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

int forky();
int programmStarty(char* spaty);
int sety();
int gety();
int spockyy(char* hans);
pid_t pid;

int main() {
	
	char string[20];
	char name[50];
	char pfad[1024];
    getcwd(pfad, sizeof(pfad));	
    strcpy(name, getenv("USERNAME"));
    system("clear");
    char input[256];
    
    while(1){
		getcwd(pfad, sizeof(pfad));	
		printf("%s@%s:\n",pfad, name);
		scanf("%s",input);
		//scanf("%s",input[1]);
		if(strcmp(input,"exit")==0){
			return 1;
		} else if(strcmp(input,"cd")==0){
			scanf("%s",input);
			chdir(input);
		} else if(strcmp(input,"set")==0){
			sety();
		} else if(strcmp(input,"get")==0){
			gety();
		} else {
			spockyy(input);
			if(pid==0){
				return 1;
			}
		}
		
	}
}


int forky(char* paffy) {
	pid = fork();
	if (pid == 0) {
		//Child
		programmStarty(paffy);
		printf("Programm beendet");	
	} else {
		//Parent
		waitpid(pid,0,0);
	}
}
int spockyy(char* hans) {
    char biny[256] = "/bin/";
    char useybiny[256] ="/usr/bin/";
	strcat(useybiny,hans);			
	strcat(biny,hans);
	if (access(useybiny, F_OK) != -1) {
		forky(useybiny);
	} else if (access(biny, F_OK) != -1) {
		forky(biny);
	} else {
		printf("Programm nicht gefunden\n");
	}
	
}

int programmStarty(char* spaty) {
	char* harry[256];
	char input[256];
	harry[0] = spaty;
	scanf("%s",input);
	printf("%s",input);
    execvp(spaty,harry);
}

//am besten an LOGNAME testen
int sety(){
    char input[256];
	printf("Als nächstes jetzt die Umgebungsvariable und seinen Wert in der Form 'name=wert' hinschreiben\n");
	scanf("%s",input);
	printf("%s\n", input);
	putenv(strdup(input));
}

int gety(){
    char input[256];
	printf("Welche Umgebungsvariable willst du checken?\n");
	scanf("%s",input);
	printf("%s\n",getenv(strdup(input)));
}

