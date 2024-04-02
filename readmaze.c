#include "readmaze.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//funkcja zwraca 1, jeżeli plik o podanej nazwie jest poprawny
//zapisuję wskaznik do pliku do struktury maze
int checkinput(char* filename,  maze* m){
	FILE *in = fopen(filename, "r");
	//sprawdzamy czy plik istnieje
	if (in == NULL){
		//plik nie istnieje
		return -1;
	}
	if (strstr(filename, ".txt") != NULL){
		//sprawdzamy poprawność pliku txt
		//printf("sprawdzamy poprawność pliku txt\n");
		return 1;
		
	} else if (strstr(filename, ".bin") != NULL){
		//sprawdzamy poprawność pliku bin
		//printf("sprawdzamy poprawność pliku bin\n");
		return 1;
		
	} else {
		//plik ma format nieobsługiwany
		return -1;
	}
	
}

void read(maze* m){

}

int checkpassage(int node_number, int direction, maze* m){
	return 0;
}
