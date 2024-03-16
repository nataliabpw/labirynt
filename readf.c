#include <stdio.h>
#include <stdlib.h>
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

void mat_fill( maze *m, char *fin){
	int lk;
	int i, j;
	int s;
	FILE *p=fopen(m->m, "r+b");
	FILE *in=fopen(fin, "r");
	if (p==NULL){
		fprintf(stderr, "Problem z plikiem preprocesora 2\n");
		exit(1);
	}
	if (in==NULL){
		fprintf(stderr, "Problem z plikiem wejściowym 2\n");
		exit(1);
	}
	lk=0;
	for(i=0; i<m->r; i++){
		for(j=0; j<m->c; j++){
			fgetc(in);
			if (fgetc(in)==' '){
				s=(i-1)*m->c*5+j*5+3;
				fseek(p, s, SEEK_SET);
				fprintf(p, "1");
				s=i*m->c*5+j*5+1;
				fseek(p, s, SEEK_SET);
				fprintf(p, "1");
			}
		}
		fgetc(in);
		fgetc(in);
		for(j=0; j<m->c; j++){
			if (fgetc(in)==' '){
				s=i*m->c*5+(j-1)*5+2;
				fseek(p, s, SEEK_SET);
				fprintf(p, "1");
				s=i*m->c*5+j*5;
				fseek(p, s, SEEK_SET);
				fprintf(p, "1");
			}
			fgetc(in);
		}
		fgetc(in);
		fgetc(in);
	}
	fclose(p);
}
