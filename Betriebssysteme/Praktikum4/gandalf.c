#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int forky();

int programmStarty();

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
		if(strcmp(input,"exit")==0){
			return 1;
		} else if(strcmp(input,"fork")==0){
			forky();
		} else if(strcmp(input,"cd")==0){
			scanf("%s",input);
			chdir(input);
		} else {
			printf("%s\n", "Falsch Eingabe");
		}
	}
}

int forky() {
	pid_t pid = fork();
	if (pid == 0) {
		//Child
		printf("BubuBaba\n");
		programmStarty();
	} else {
		//Parent
		waitpid(0,NULL,WNOHANG);
		printf("Daddy\n");
	}
}

int programmStarty() {
    char input[256];
	scanf("%s",input);
	printf("%s\n", input);
}
