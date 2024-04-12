#include <stdio.h>
#include "maze.h"
#include "readmaze.h"
#include "path.h"
#include "printpath.h"
#include "solvemaze.h"
#include "checkparams.h"
#include <stdbool.h>
int main( int argc, char **argv){

	params_str params = {false, "", "", false};
	checkparams(&params, argc, argv);
	if (params.help == true){
		printf("HELP!\n");
		return 0;
	}
	
	if (params.inputFileName == NULL){
		printf("musi być podana nazwa pliku z labiryntem\n");
		return 0;
	}
	
	if (params.outputToFile == true){
		printf("ścieżka będzie zapisana do pliku: %s\n", params.fileName);
	}
	
	char* inputFileName = params.inputFileName;
	
	maze maze_str = {NULL, 0, 0, 0, 0, 0};
	path p;
	int resultcheck = checkinput(inputFileName, &maze_str);
	if(resultcheck == FILE_ACCEPTED_CONST){
		//plik poprawny
		printf("plik poprawny\n");
		//odczytujemy z pliku dane o labiryncie
		read(&maze_str);
		printf("columns: %d, rows: %d\n", maze_str.columns, maze_str.rows);
		printf("begin: %d, end: %d\n", maze_str.begin, maze_str.end);
  	solve(&maze_str, &p);
		print_pathh( &p, &maze_str);	
		
	} else {
		//plik niepoprawny
		printf("plik niepoprawny\n");
	}
	return 0;
}
