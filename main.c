#include <stdio.h>
#include <stdlib.h>
#include "size.h"
#include "read.h"

int main( int argc, char ** argv){
	FILE *in = argc>1 ? fopen(argv[1], "r"): NULL;
	int r=0;
	int c=0;
	int k=0;
	int blocks;
	int *s;
	int i,j;
	size( in, &r, &c);
	fclose(in);
	k=c*r;
	/*if((c%2==0 && c/2<=7) || (c%2==1 && c/2<7)){
	       blocks=r;
       	else if((c/2)%7==0 && c%7==1){
		blocks = r/2*c/2 +r/2;*/
	blocks=(c/2)/7+1;
	//if c%7==0, if c%2==1
	s=calloc(r*blocks,sizeof(int));
	printf("%d %d\n", blocks, r*blocks);
	in = fopen(argv[1], "r");
	read( s, in, r, c, blocks);
	/*for(i=0;i<r;i++){
		for(j=0; j<blocks; j++)
			printf("%d\n", s[i*blocks+j]);
	}*/
	for(i=0; i<r*blocks; i++)
		printf("%d\n", s[i]);
	return 0;
}
