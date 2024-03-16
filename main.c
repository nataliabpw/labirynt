#include <stdio.h>
#include "maze.h"
#include "readf.h"

int main( int argc, char **argv){
	FILE *in = argc>1 ? fopen(argv[1], "r"): NULL;
	FILE *p;
	int i;
	maze m;
	if (in==NULL){
		fprintf(stderr, "Problem z plikiem wejściowym\n"); //poprawić na kilka przypadków -> jaśniejsze komunikaty
		return 1;
	}

	// Rozmiar + tu zrobić obsługę błędów związanych z strukturą pliku wejściowego
	size(&m, in);
	printf("Wiersze: %d\nKolumny: %d\n", m.r, m.c);
	m.n=m.r*m.c;

	// Inicjacja macierzy
	m.m="p";
	p=fopen(m.m, "w");
	if (p==NULL){
		fprintf(stderr, "Problem z plikiem preprocesora 1\n");
		return 1;
	}
	for (i=0; i<m.n; i++){
		fprintf(p, "0000\n");
	}
	fclose(p);

	// Uzupełnienie macierzy
	mat_fill( &m, argv[1]);

	return 0;
}
