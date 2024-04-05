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
int checkpassageTXT(int node_number, int direction, maze* m){
	FILE* input = m->in;
	char temp;
	switch(direction){
		case DIRECTION_LEFT:
			//printf("left\n");
			//printf("node byte: %d\n", node_byte(node_number, m));
			fseek(input, node_byte(node_number, m)-1, SEEK_SET);
			temp = fgetc(input);
			//printf("temp: %c\n", temp);
			if(temp == ' ' || temp == 'K' || temp == 'P'){
				printf("yes\n");
				return PASSAGE_CONST;
			}else{
				printf("no\n");
				return NOT_PASSAGE_CONST;
			}
				
			break;

		case DIRECTION_TOP:
			printf("top\n");
			return NOT_PASSAGE_CONST;
			break;
		case DIRECTION_RIGHT:
			//printf("right\n");
			//printf("node byte: %d\n", node_byte(node_number, m));
			fseek(input, node_byte(node_number, m)+1, SEEK_SET);
			temp = fgetc(input);
			//printf("temp: %c\n", temp);
			if(temp == ' ' || temp == 'K' || temp == 'P'){
				printf("yes\n");
				return PASSAGE_CONST;
			}else{
				printf("no\n");
				return NOT_PASSAGE_CONST;
			}
				
			break;
		case DIRECTION_BOTTOM:
			printf("bottom\n");
			return NOT_PASSAGE_CONST;
			break;
	}
	//nieznana wartość direction
	return NOT_PASSAGE_CONST;
}
int node_byte(int node_number, maze* m){
	int lines = ((node_number/m->columns) + 1);
	//printf("lines: %d\n", lines);
	int binl = (m->columns*2) + 1;
	//printf("binl: %d\n", binl);
	int full = ((lines*2) - 1)*binl + (lines-1)*2;
	//printf("full: %d\n", full);
	int add = node_number - ((lines-1)*m->columns);
	//printf("add: %d\n", add);
	return (full + (add*2));
}
