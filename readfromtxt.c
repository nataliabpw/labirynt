#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
#include "readfromtxt.h"
//funkcja zwraca FILE_ACCEPTED_CONST, jeżeli plik jest poprawny
int checkinputTXT(maze* m){
	FILE* input = m->in;
	fseek(input, 0, SEEK_SET);
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
	return FILE_ACCEPTED_CONST;
}
//funkcja zapisuje do struktury maze informację o początku, końcu, rozmiarach labiryntu
void readTXT(maze* m){
	FILE* input = m->in;
	char temp;
	int charNumber = 0;
	int actualCharNumber = 0;
	int squareNumber = 1;
	int lineNumber = 1;
	fseek(input, 0, SEEK_SET);
	while(fscanf(input, "%c", &temp) == 1){
	//printf("%c",temp);
		actualCharNumber++;
		if(lineNumber == 1){
			charNumber++;
		}
		if (temp == '\n'){
			actualCharNumber=0;
			if(lineNumber == 1){
				//printf("%d\n", charNumber);
				m->columns = charNumber / 2 - 1;
			}
			lineNumber++;
		}
		if (temp == 'P'){
			//printf("%d, %d, %d, ", lineNumber, charNumber, actualCharNumber);
			m->begin = ((lineNumber-1) / 2)*((charNumber-1)/ 2) + (actualCharNumber/2) +1;
		}
		if (temp == 'K'){
			m->end = ((lineNumber-1) / 2)*((charNumber-1)/ 2) + (actualCharNumber/2);
		}
	}
	//printf("%d\n", lineNumber);
	m->rows = lineNumber / 2 - 1;
}

