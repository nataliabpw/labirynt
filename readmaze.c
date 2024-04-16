#include "readmaze.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readfromtxt.h"
#include "readfrombin.h"
//funkcja zwraca FILE_ACCEPTED_CONST, jeżeli plik o podanej nazwie jest poprawny
//zapisuję wskaznik do pliku do struktury maze
int checkinput(char* filename,  maze* m){
	FILE *in = fopen(filename, "r");
	//sprawdzamy czy plik istnieje
	if (in == NULL){
		printf("plik nie istnieje\n");
		return FILE_NOT_ACCEPTED_CONST;
	}
	
	if (strstr(filename, ".txt") != NULL){
		m->in=in;
		//sprawdzamy poprawność pliku txt
		//printf("sprawdzamy poprawność pliku txt\n");
		m->inputtype = INPUT_TYPE_TXT_CONST;
		int result = checkinputTXT(m);
		return result;
		
	} else if (strstr(filename, ".bin") != NULL){
		fclose(in);
		in = fopen(filename, "rb");
		m->in=in;
		//sprawdzamy poprawność pliku bin
		//printf("sprawdzamy poprawność pliku bin\n");
		m->inputtype = INPUT_TYPE_BIN_CONST;
		int result = checkinputBIN(m);
		return result;
		
	} 
	//plik ma format nieobsługiwany
	printf("Plik ma nieobsługiwany format\n");
	return FILE_NOT_ACCEPTED_CONST;
	
	
}

void read(maze* m){
	switch (m->inputtype){
	case INPUT_TYPE_TXT_CONST:
		//odczytujemy z pliku txt
		readTXT(m);
		break;
	case INPUT_TYPE_BIN_CONST:
		//odczytujemy z pliku bin
		readBIN(m);
		break;
	}
}

int checkpassage(int node_number, int direction, maze* m, unsigned char * buffer, int bufsize){
	switch (m->inputtype){
	case INPUT_TYPE_TXT_CONST:
		//sprawdzamy przejście w pliku txt
		return checkpassageTXT(node_number, direction, m);
		break;
	case INPUT_TYPE_BIN_CONST:
		//sprawdzamy przejście w pliku bin
		return checkpassageBIN(node_number, direction, m, buffer, bufsize);
		break;
	}
	return 0;
}
