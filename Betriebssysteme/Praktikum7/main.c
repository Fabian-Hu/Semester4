#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> /* fuer Kontrollfluss */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int copyWeirdToFile(char** argv, int filedesc);
int copyToFile (char** argv);
void weirdAusgabe(int filedesc, int sizeContent);
void normaleAusgabe(char** argv);
off_t getLengthOfFile(int filedesc);
char *content;

int main(int argc, char** argv){
	int copiedFiledesc;
	write(STDOUT_FILENO,"\n",strlen("\n"));
    int filedesc = open(argv[1], O_RDONLY);
    if(filedesc < 0)
        return 1;

	off_t off = getLengthOfFile(filedesc);
	content = (char*) malloc((int) off * sizeof(char));
	weirdAusgabe(filedesc,(int)off);
	copyToFile(argv);
    write(STDOUT_FILENO,"\n\nAufgabe 2:\n",strlen("\n\nAufgabe 4:\n"));
    normaleAusgabe(argv);
	copiedFiledesc = copyWeirdToFile(argv, filedesc);
    write(STDOUT_FILENO,"\n\nAufgabe 4:\n",strlen("\n\nAufgabe 4:\n"));
	normaleAusgabe(argv);
    close(filedesc);
    close(copiedFiledesc);
}

void normaleAusgabe(char** argv) {

    int filedesc = open(argv[2], O_RDONLY);
	off_t off = getLengthOfFile(filedesc);
    lseek(filedesc, 0, SEEK_SET);
	char content[off-1];
	read(filedesc, content, sizeof(content));
    write(STDOUT_FILENO,content,strlen(content)); // ausgabe
	write(STDOUT_FILENO,"\n",strlen("\n"));
}

void weirdAusgabe(int filedesc,int sizeContent) {
	lseek(filedesc, 0, SEEK_SET);

	off_t off = getLengthOfFile(filedesc);
    memset(content, 1, sizeContent);

    lseek(filedesc, off/2, SEEK_SET);
    ssize_t size = read(filedesc, content, sizeContent);
    write(STDOUT_FILENO,content,strlen(content)/2); // ausgabe

	write(STDOUT_FILENO,"\n\n",strlen("\n\n"));

    memset(content, 1, sizeof(content));
    lseek(filedesc, 0, SEEK_SET);
    size = read(filedesc, content, sizeContent);
    write(STDOUT_FILENO,content,strlen(content)/2); // ausgabe

}

off_t getLengthOfFile(int filedesc) {
	lseek(filedesc, 0, SEEK_SET);
	off_t off = lseek(filedesc, 0, SEEK_END);
    if (off == (off_t)-1)
    {
        printf("failed to lseek \n");
        close(filedesc);
        return 1;
    }
	lseek(filedesc, 0, SEEK_SET);
    return off;
}

int copyToFile (char** argv) {
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	int filedesc = open(argv[2], O_CREAT | O_WRONLY, mode);
	if(filedesc < 0) {
        return 1;
	}

    if(write(filedesc,content, strlen(content)) != strlen(content))
    {
		close(filedesc);
		return 1;
    }
    close(filedesc);
    return filedesc;
}

int copyWeirdToFile(char** argv, int oldFiledesc) {
	//neue Datei öffnen
	int filedesc = open(argv[2], O_RDWR);

	//aus der alten Datei die letzten 10 Zeichen auslesen und in lastChars packen
	char lastChars[10];
	off_t off = getLengthOfFile(oldFiledesc);
	lseek(oldFiledesc, off-11, SEEK_SET);
    read(oldFiledesc, lastChars, 10);

    //die zweite Hälfte der neuen Datei in lastHalf speichern
    //hier ist vermutlich ein Fehler
	off_t offHalf = getLengthOfFile(filedesc);
	lseek(filedesc, 11, SEEK_SET);
	char lastHalf[offHalf-11];
    read(filedesc, lastHalf, offHalf-11);
    //off funktioniert, lastHalf ist kaputt
    //printf("\nlastChars: \n%s\nlänge: \n %li\n", lastChars, strlen(lastChars));
    //printf("\nlastHalf: \n%s\nlänge: \n %li\n", lastHalf, strlen(lastHalf));

 //   ftruncate(filedesc, 11);
    //lastChars ab der 11. Stelle schreiben und die Datei da überschreiben
    if(write(filedesc,lastChars, 10) != 10)
    {
		close(filedesc);
		return 1;
    }

	//lastHalf ab der 21. Stelle schreiben und die Datei überschreiben
	//hier könnte auch ein Fehler sein
	lseek(filedesc, 21, SEEK_SET);
	if(write(filedesc,lastHalf, offHalf-11) != offHalf-11)
    {
		close(filedesc);
		return 1;
    }

	return filedesc;
}
