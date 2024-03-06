#include <stdlib.h>
#include "size.h"

void size(FILE *in, int *r, int *c){
	char z;
	if (in==NULL){
		fprintf(stderr, "Problem z plikiem!\n");
		exit(1);
	}
	while ((z=fgetc(in))!='\n')
		(*c)++;
	(*r)++;

	while ((z=fgetc(in))!=EOF)
		if (z=='\n')
			(*r)++;
	*c/=2;
	*r/=2;
}
