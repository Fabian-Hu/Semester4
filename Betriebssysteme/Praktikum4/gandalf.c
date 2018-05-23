#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int forky();
int programmStarty();
int sety();

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
		if(strcmp(input,"exit")==0){
			return 1;
		} else if(strcmp(input,"fork")==0){
			forky();
			if(pid==0){
				return 1;
			}
			//system("clear");
		} else if(strcmp(input,"cd")==0){
			scanf("%s",input);
			chdir(input);
		} else if(strcmp(input,"set")==0){
			sety();
		} else {
			printf("%s\n", "Falsch Eingabe");
		}
		
	}
}

int forky() {
	pid = fork();
	if (pid == 0) {
		//Child
		printf("Jetzt brauchen wir deinen Programmnamen:\n");
		programmStarty();
		
	} else {
		//Parent
		waitpid(pid,0,0);
	}
}

int programmStarty() {
    char input[256]="";
    char path[256];
    char biny[256] = "/bin/";
    char useybiny[256] ="/usr/bin/";
    char zwischy[256] = "";
    //Bei firefox macht er es richtig, sonst total falsch
	do {
		scanf("%s",input);
		strcat(zwischy, input);
		printf("%s", zwischy);
	} while (!strcmp(input,"")); 


	//realpath(input, path);
	strcat(useybiny,zwischy);
	//möglicherweise klappt die if Bedingung, printf will es uns aber nicht sagen
	if (access(useybiny, F_OK) != -1) {
		printf("ja");
		//Die Parameterliste müssen wir noch einmal prüfen
		execlp(useybiny,zwischy, NULL);
	} else {
		printf("nein");
		strcat(biny,zwischy);
		
		//Die Parameterliste müssen wir noch einmal prüfen
		execvp(biny, zwischy);
	}
}

//Hier fehlt quasi alles
int sety(){
	printf("Hier werden irgendwann Umgebungsvariablen gesetzt\n");
}
