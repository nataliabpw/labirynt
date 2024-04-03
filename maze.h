#ifndef MAZE_H
#define MAZE_H
#define FILE_ACCEPTED_CONST 1
#define FILE_NOT_ACCEPTED_CONST -1
typedef struct{
	FILE* in;
	int inputtype;
	int begin; //numer komurki początkowej
	int end; //numer komurki końcowej
	int colums;
	int rows;
} maze;
#endif
