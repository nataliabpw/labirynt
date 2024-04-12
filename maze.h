#ifndef MAZE_H
#define MAZE_H
#define FILE_ACCEPTED_CONST 1
#define FILE_NOT_ACCEPTED_CONST -1
#define INPUT_TYPE_TXT_CONST 100
#define INPUT_TYPE_BIN_CONST 101
#define PASSAGE_CONST 10
#define NOT_PASSAGE_CONST 11
#define DIRECTION_LEFT 20
#define DIRECTION_TOP 21
#define DIRECTION_RIGHT 22
#define DIRECTION_BOTTOM 23

#include <stdio.h>

typedef struct{
	FILE* in;
	int inputtype;
	int begin; //numer komórki początkowej
	int end; //numer komórki końcowej
	int columns;
	int rows;
} maze;
#endif
