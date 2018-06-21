#include "filesystem.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
	if (argc != 3) {
		return EXIT_FAILURE;
	}
	
	int file = open(argv[1], O_RDONLY);
	ERROR(file);
	
	int destFile = open(argv[2], O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IROTH);
	ERROR(destFile);
	readFile(file, destFile);
	
	ERROR(close(file));
	ERROR(close(destFile));
}

void simpleWrite(int dest, const char *content, size_t len) {
	int count = len;
	while (count) {
		count -= ERROR(write(dest, content, len));
	}
}

void writeTo(int dest1, int dest2, char *content1, size_t len1, char *content2, size_t len2) {
	simpleWrite(dest1, content2, len2);
	simpleWrite(dest1, &eol, 1);
	simpleWrite(dest1, content1, len1);
	simpleWrite(dest1, &eol, 1);
	simpleWrite(dest2, content1, len1);
	simpleWrite(dest2, content2, len2);
}

void readFile(int file, int destFile) {
	off_t eof = lseek(file, 0, SEEK_END);
	ERROR(eof);
	
	off_t half1 = eof / 2;
	off_t half2 = eof - half1;
	ERROR(lseek(file, half2, SEEK_SET));
	
	char contentSecond[half1];
	ERROR(read(file, contentSecond, half1));
	
	ERROR(lseek(file, 0, SEEK_SET));
	
	char contentFirst[half2];
	ERROR(read(file, contentFirst, half2));
	
	writeTo(STDOUT_FILENO, destFile, contentFirst, half2, contentSecond, half1);
	
	char completeContent[eof];
	strcpy(completeContent, contentFirst);
	strcpy(&completeContent[half2], contentSecond);
	off_t lastTen = (eof - 10 >= 0) ? eof - 10 : 0;
	ERROR(lseek(destFile, 11, SEEK_SET));
	int length = (eof - 11 >= 0) ? 10 : eof - lastTen;
	simpleWrite(destFile, &completeContent[lastTen], length);
	if (eof > 11) {
		simpleWrite(destFile, &completeContent[11], eof - 11 /*- length*/);
	}
	
	ERROR(ftruncate(destFile, eof + length));
	
	off_t destEof = lseek(destFile, 0, SEEK_END);
	ERROR(destEof);
	ERROR(lseek(destFile, 0, SEEK_SET));
	char destContent[destEof];
	ERROR(read(destFile, destContent, destEof));
	simpleWrite(STDOUT_FILENO, destContent, destEof);
	
}


int ERROR(int result) {
	if (result == -1) {
		char *msg = strerror(errno);
		size_t len = strlen(msg);
		write(STDERR_FILENO, msg, len);
		write(STDERR_FILENO, &eol, 1);
		exit(EXIT_FAILURE);
	}
	return result;
}
