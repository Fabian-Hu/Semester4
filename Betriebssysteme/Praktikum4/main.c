#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <strings.h>

int fileExists(const char *filename) {
	FILE *file;
	if ((file = fopen(filename, "r")) != NULL) {
		fclose(file);
		return 1;
	}
	return 0;
}

void parseInput(char *argv[]) {
	char delim[] = " ";
	char *token = strtok(NULL, delim);
	size_t argvPos = 1;
	char *env;
	while(token != NULL) {
		if (token[0] == '$' && (env = getenv(token + 1)) != NULL) {
			argv[argvPos] = env;
			argvPos++;
			
		}else if (argvPos < 32){
			argv[argvPos] = token;
			argvPos++;
		}
		token = strtok(NULL, delim);
	}
	argv[argvPos] = NULL;
}

int startProgramm(char *name){
	int exist = 0;
	char realname[64];
	if (fileExists(name)) {
		exist = 1;
		realpath(name, realname);
	} else {
		char path[50];
		char *bin = "/bin/";
		strcat(path, bin);
		strcat(path, name);
		if (fileExists(path)) {
			exist = 1;
			strcpy(realname, path);
		} else {
			printf("Datei nicht gefunden.");
		}
	}
	if (exist) {
		char *argv[32];
		argv[0] = realname;
		
		parseInput(argv);
		
		pid_t pid = fork();
		if (pid == (pid_t)0) {
			execvp(realname, argv);	
		} else if (pid > (pid_t)0) {
			waitpid(pid, NULL, 0);
		} else {
			printf("Programm konnte nicht gestartet werden");
		}
	}
	return 0;
}

void setEnv() {
	char *var = strtok(NULL, " ");
	if (var != NULL)
		putenv(strdup(var));
}

int main() {
	int running = 1;
	char buffer[1024];
	char *user = getenv("USER");
	char path[1024];
	
	while(running) {
		getcwd(path, sizeof(path));
		printf("%s@%s: ", user, path);
		scanf("%[^\n]%*c", buffer);
		
		char *cmd = strtok(buffer, " ");
		
		if (!strcmp(cmd, "exit")) {
			running = 0;
		} else if (!strcmp(cmd, "cd")) {
			chdir(strtok(NULL, " "));
		} else if (!strcmp(cmd, "set")) {
			setEnv();
		} else {
			startProgramm(cmd);
		}
		printf("\n");
	}
	return 0;
}
