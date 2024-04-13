#include <stdio.h>
#include "maze.h"
#include "readmaze.h"
#include "path.h"
#include "printpath.h"
#include "solvemaze.h"

int main( int argc, char **argv){
	maze maze_str = {NULL, 0, 0, 0, 0, 0};
	path p;
	int x=9;
	int resultcheck = checkinput(argv[1], &maze_str);
	if(resultcheck == FILE_ACCEPTED_CONST){
		//plik poprawny
		printf("plik poprawny\n");
		
		//odczytujemy z pliku dane o labiryncie
		read(&maze_str);
		printf("columns: %d, rows: %d\n", maze_str.columns, maze_str.rows);
		printf("begin: %d, end: %d\n", maze_str.begin, maze_str.end);
		
		//przykład sprawdzenia prejść:

		/*
		if (checkpassage(518, DIRECTION_LEFT, &maze_str) == PASSAGE_CONST){
			printf("prejście na lewo jest\n");
		} else{
			printf("przejścia na lewo nie ma\n");
		};
    		*/
    		solve(&maze_str, &p);
		print_path( &p, &maze_str);	
		
	} else {
		//plik niepoprawny
		printf("plik niepoprawny\n");
	}
	return 0;
}
