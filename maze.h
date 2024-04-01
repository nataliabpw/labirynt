#ifndef MAZE_H
#define MAZE_H
typedef struct{
	FILE* in;
	int inputtype;
	int begin; //numer komurki początkowej
	int end; //numer komurki końcowej
	int colums;
	int rows;
} maze;
#endif
