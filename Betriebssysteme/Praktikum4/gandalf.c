#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main() {
	char string[20];
	char name[50];
	char pfad[1024];
    getcwd(pfad, sizeof(pfad));	
    strcpy(name, getenv("USERNAME"));
    system("clear");
    char input[256];
    
    while(1){
		printf("%s@%s\n",pfad, name);
		scanf("%s",input);
		if(strcmp(input,"exit")==0){
			sreturn 1;
		}
	}
}
