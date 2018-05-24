#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

int forky(char* paffy[256]);
int programmStarty(char* spaty[256]);
int sety(char* rip[256]);
int gety(char* rip2[256]);
void parsusMaximus(char *input[]);
int spockyy(char* hans[256]);
pid_t pid;

int main() {
	char name[50];
	char pfad[1024];
    getcwd(pfad, sizeof(pfad));	
    strcpy(name, getenv("USERNAME"));
    system("clear");
    char* input[256];
    
    while(1){
		getcwd(pfad, sizeof(pfad));	
		printf("%s@%s:\n",pfad, name);
		parsusMaximus(input);
		
		if(strcmp(input[0],"exit")==0){
			return 1;
		} else if(strcmp(input[0],"cd")==0){
			chdir(input[1]);
		} else if(strcmp(input[0],"set")==0){
			sety(input);
		} else if(strcmp(input[0],"get")==0){
			gety(input);
		} else {
			spockyy(input);
			if(pid==0){
				return 1;
			}
		}
	}
}

int forky(char* paffy[256]) {
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

int spockyy(char* hans[256]) {
	printf("%s",hans[0]);
    char biny[256] = "/bin/";
    char useybiny[256] ="/usr/bin/";
	strcat(useybiny,hans[0]);			
	strcat(biny,hans[0]);
	if (access(useybiny, F_OK) != -1) {
		hans[0] = useybiny;
		forky(hans);
	} else if (access(biny, F_OK) != -1) {
		hans[0] = biny;
		forky(hans);
	} else {
		printf("Programm nicht gefunden\n");
	}
}

int programmStarty(char* spaty[256]) {
    execvp(spaty[0],spaty);
}

//am besten an LOGNAME testen
int sety(char* rip[256]){
	putenv(strdup(rip[1]));
}

int gety(char* rip2[256]){
	printf("%s\n",getenv(strdup(rip2[1])));
}

void parsusMaximus(char *input[]) {
	int i = 0;
	
	while(1){
		char string[256];
		scanf("%s",string);
		if(strcmp(string,";")==0){
			break;
		}	
		input[i] = strdup(string);
		i++;
	}
}
