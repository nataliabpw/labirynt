#include <stdio.h>
#include "maze.h"
#include "readmaze.h"
int main( int argc, char **argv){
	maze maze_str = {NULL, 0, 0, 0, 0, 0};
	int resultcheck = checkinput(argv[1], &maze_str);
	if(resultcheck == FILE_ACCEPTED_CONST){
		//plik poprawny
		printf("plik poprawny\n");
	} else {
		//plik niepoprawny
		printf("plik niepoprawny\n");
	}
	return 0;
}
