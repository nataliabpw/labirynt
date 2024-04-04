#ifndef MAZE_H
#define MAZE_H
#define FILE_ACCEPTED_CONST 1
#define FILE_NOT_ACCEPTED_CONST -1
#define INPUT_TYPE_TXT_CONST 100
#define INPUT_TYPE_BIN_CONST 101
typedef struct{
	FILE* in;
	int inputtype;
	int begin; //numer komurki początkowej
	int end; //numer komurki końcowej
	int columns;
	int rows;
} maze;
#endif
