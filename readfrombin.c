#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
#include "readfrombin.h"

//funkcja zwraca FILE_ACCEPTED_CONST, jeżeli plik jest poprawny
int checkinputBIN(maze* m){
	return FILE_ACCEPTED_CONST;
}
//funkcja zapisuje do struktury maze informację o początku, końcu, rozmiarach labiryntu
void readBIN(maze* m){
	FILE* input = m->in;
	
	//FILE ID
	int temp;
	fread(&temp, 4, 1, input);

	//ESCAPE
	temp = 0;
	fread(&temp, 1, 1, input);
	
	//COLUMNS AND ROWS
	temp = 0;
	fread(&temp, 2, 1, input);
	m->columns = (temp-1)/2;
	temp = 0;
	fread(&temp, 2, 1, input);
	m->rows = (temp-1)/2;
	
	//ENTRYX AND ENTRYY
	int entryX, entryY;
	temp = 0;
	fread(&temp, 2, 1, input);
	entryX = temp;
	temp = 0;
	fread(&temp, 2, 1, input);
	entryY = temp;
	m->begin =  ((entryY/2)-1)*m->columns + (entryX/2) + 1;
	
	//EXITX AND EXITY
	int exitX, exitY;
	temp = 0;
	fread(&temp, 2, 1, input);
	exitX = temp;
	temp = 0;
	fread(&temp, 2, 1, input);
	exitY = temp;
	m->end =  ((exitY/2)-1)*m->columns + (exitX/2);
	
	//reserved
	temp = 0;
	fread(&temp, 12, 1, input);
	
	//counter
	temp = 0;
	fread(&temp, 4, 1, input);
	
	//solution offset
	temp = 0;
	fread(&temp, 4, 1, input);
	
	//opis słów kodowych
	//separator
	temp = 0;
	fread(&temp, 1, 1, input);
	//printf("separator: '%c'\n", temp);
	
	//wall
	temp = 0;
	fread(&temp, 1, 1, input);
	//printf("wall: '%c'\n", temp);
	
	//path
	temp = 0;
	fread(&temp, 1, 1, input);
}

typedef struct{
	int separator;
	int value;
	int count;
} code_word_str;

void readCodeWord(code_word_str *codeWord, FILE* input, unsigned char * buffer, int block){
	//fread(buffer,1,3,input);
	codeWord->separator = buffer[0+block*3];
	codeWord->value = buffer[1+block*3];
	codeWord->count = buffer[2+block*3];
	
}
int value_number(int node_number, maze* m){
	int lines = (((node_number-1)/m->columns) + 1);
	int binl = (m->columns*2) + 1;
	int full = ((lines*2) - 1)*binl;
	int add = node_number - ((lines-1)*m->columns);
	return (full + (add*2));
}
int checkpassageBIN(int node_number, int direction, maze* m, unsigned char * buffer, int bufsize){
	
	code_word_str codeWord = {0, 0, 0};
	int block=0;
	
	FILE* input = m->in;
	
	fseek(input, 40, SEEK_SET); //przehodzimy na początek sekcji "słowa kodowe"
	int symbolToCheck;
	int actualSymbol;
	switch (direction){
		case DIRECTION_LEFT:
			symbolToCheck = value_number(node_number, m) - 1; // - 1 bo jedziemy na lewo
			actualSymbol = 0;
			while(actualSymbol < symbolToCheck){
				if (block==0)
					fread(buffer,1,bufsize,input);
				readCodeWord(&codeWord, input, buffer, block);
				block=(block+1)%(bufsize/3);
				actualSymbol += 1 + codeWord.count;
			}
			if(codeWord.value == 'X'){
				return NOT_PASSAGE_CONST;
			}
			return PASSAGE_CONST;
			break;
		case DIRECTION_TOP:
			symbolToCheck = value_number(node_number, m);
			symbolToCheck = symbolToCheck - (m->columns*2) - 1;
			actualSymbol = 0;
			while(actualSymbol < symbolToCheck){
				if (block==0)
					fread(buffer,1,bufsize,input);
				readCodeWord(&codeWord, input, buffer, block);
				block=(block+1)%(bufsize/3);
				actualSymbol += 1 + codeWord.count;
			}
			if(codeWord.value == 'X'){
				return NOT_PASSAGE_CONST;
			}
			return PASSAGE_CONST;
			break;
		case DIRECTION_RIGHT:
			symbolToCheck = value_number(node_number, m) + 1; // + 1 bo jedziemy na lewo
			actualSymbol = 0;
			while(actualSymbol < symbolToCheck){
				if (block==0)
					fread(buffer,1,bufsize,input);
				readCodeWord(&codeWord, input, buffer, block);
				block=(block+1)%(bufsize/3);
				actualSymbol += 1 + codeWord.count;
			}
			if(codeWord.value == 'X'){
				return NOT_PASSAGE_CONST;
			}
			return PASSAGE_CONST;
			break;
		case DIRECTION_BOTTOM:
			symbolToCheck = value_number(node_number, m);
			symbolToCheck = symbolToCheck + (m->columns*2) + 1;
			actualSymbol = 0;
			while(actualSymbol < symbolToCheck){
				if (block==0)
					fread(buffer,1,bufsize,input);
				readCodeWord(&codeWord, input, buffer, block);
				block=(block+1)%(bufsize/3);
				actualSymbol += 1 + codeWord.count;
			}
			if(codeWord.value == 'X'){
				return NOT_PASSAGE_CONST;
			}
			return PASSAGE_CONST;
			break;
	}
	return NOT_PASSAGE_CONST;
}
