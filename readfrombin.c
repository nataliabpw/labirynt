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
	
	int temp;
	fread(&temp, 4, 1, input);
	//printf("file id: %d\n", temp);
	temp = 0;
	fread(&temp, 1, 1, input);
	//printf("escape: %d\n", temp);
	
	temp = 0;
	fread(&temp, 2, 1, input);
	//printf("columns: %d\n", temp);
	m->columns = (temp-1)/2;
	temp = 0;
	fread(&temp, 2, 1, input);
	//printf("lines: %d\n", temp);
	m->rows = (temp-1)/2;
	
	int entryX, entryY;
	temp = 0;
	fread(&temp, 2, 1, input);
	entryX = temp;
	temp = 0;
	fread(&temp, 2, 1, input);
	entryY = temp;
	//printf("entryx: %d, entryy: %d\n", entryX, entryY);
	m->begin =  ((entryY/2)-1)*m->columns + (entryX/2) + 1;
	
	int exitX, exitY;
	temp = 0;
	fread(&temp, 2, 1, input);
	exitX = temp;
	temp = 0;
	fread(&temp, 2, 1, input);
	exitY = temp;
	//printf("exitx: %d, exity: %d\n", exitX, exitY);
	m->end =  ((exitY/2)-1)*m->columns + (exitX/2);
	
	//tego chyba nie musimy używać
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
	printf("separator: '%c'\n", temp);
	
	//wall
	temp = 0;
	fread(&temp, 1, 1, input);
	printf("wall: '%c'\n", temp);
	
	//path
	temp = 0;
	fread(&temp, 1, 1, input);
	printf("path: '%c'\n", temp);
}
int checkpassageBIN(int node_number, int direction, maze* m){
	
	return NOT_PASSAGE_CONST;
}


