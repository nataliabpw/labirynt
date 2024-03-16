#include <stdio.h>
#include "maze.h"
#include "readf.h"

int main( int argc, char **argv){
	FILE *in = argc>1 ? fopen(argv[1], "r"): NULL;
	maze m;
	if (in==NULL){
		fprintf(stderr, "Problem z plikiem wejściowym\n"); //poprawić na kilka przypadków -> jaśniejsze komunikaty
		return 1;
	}
	size(&m, in);
	printf("Wiersze: %d\nKolumny: %d\n", m.r, m.c);
	return 0;
}
