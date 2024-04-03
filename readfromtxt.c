#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
#include "readfromtxt.h"

//funkcja zwraca FILE_ACCEPTED_CONST, jeżeli plik jest poprawny
int checkinputTXT(maze* m){
	FILE* input = m->in;
	char temp;
	int line = 1;
	int charNumberInFirstLine = 0;
	int charNumberInLine = 0;
	while(fscanf(input, "%c", &temp) == 1){
		if(line == 1){
			charNumberInFirstLine++;
		} else{
			charNumberInLine++;
		}
		if (temp != 'X' && temp != 'P' && temp != 'K' && temp != ' ' && temp != '\n'){
			//plik zawiera nieobsługiwane symbole
			return FILE_NOT_ACCEPTED_CONST;
		}
		if (temp == '\n' && line!=1){
			//printf("%d %d\n", charNumberInLine, charNumberInFirstLine);
			if(charNumberInLine != charNumberInFirstLine){
				//plik nie jest "kwadratowy"
				return FILE_NOT_ACCEPTED_CONST;
			}
		}
		if(temp == '\n'){
			charNumberInLine=0;
			line++;
		}
	}
	//printf("%d %d\n", line, charNumberInFirstLine);
	if (line != charNumberInFirstLine){
		//plik nie jest "kwadratowy"
		return FILE_NOT_ACCEPTED_CONST;
	}
	return FILE_ACCEPTED_CONST;
}
