#include "readmaze.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readfromtxt.h"
//funkcja zwraca FILE_ACCEPTED_CONST, jeżeli plik o podanej nazwie jest poprawny
//zapisuję wskaznik do pliku do struktury maze
int checkinput(char* filename,  maze* m){
	FILE *in = fopen(filename, "r");
	//sprawdzamy czy plik istnieje
	if (in == NULL){
		//plik nie istnieje
		return FILE_NOT_ACCEPTED_CONST;
	}
	m->in=in;
	if (strstr(filename, ".txt") != NULL){
		//sprawdzamy poprawność pliku txt
		//printf("sprawdzamy poprawność pliku txt\n");
		int result = checkinputTXT(m);
		return result;
		
	} else if (strstr(filename, ".bin") != NULL){
		//sprawdzamy poprawność pliku bin
		//printf("sprawdzamy poprawność pliku bin\n");
		return FILE_ACCEPTED_CONST;
		
	} 
	//plik ma format nieobsługiwany
	return FILE_NOT_ACCEPTED_CONST;
	
	
}

void read(maze* m){

}

int checkpassage(int node_number, int direction, maze* m){
	return 0;
}
