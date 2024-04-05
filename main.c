#include <stdio.h>
#include "maze.h"
#include "readmaze.h"
int main( int argc, char **argv){
	maze maze_str = {NULL, 0, 0, 0, 0, 0};
	int resultcheck = checkinput(argv[1], &maze_str);
	if(resultcheck == FILE_ACCEPTED_CONST){
		//plik poprawny
		printf("plik poprawny\n");
		read(&maze_str);
		printf("columns: %d, rows: %d\n", maze_str.columns, maze_str.rows);
		printf("begin: %d, end: %d\n", maze_str.begin, maze_str.end);
		checkpassage(1, DIRECTION_RIGHT, &maze_str);
		checkpassage(3, DIRECTION_LEFT, &maze_str);
	} else {
		//plik niepoprawny
		printf("plik niepoprawny\n");
	}
	return 0;
}
