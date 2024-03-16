#include <stdio.h>
#include "readf.h"

void size( maze *m, FILE *in){
	char i;
	m->c=0;
	m->r=0;
	while ((i=fgetc(in))!='\n'){
		(m->c)++;
	}
	(m->r)++;
	while ((i=fgetc(in))!=EOF){
		if (i=='\n'){
			(m->r)++;
		}
	}
	(m->r)/=2;
	(m->c)/=2;
}
