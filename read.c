#include <stdio.h>
#include "read.h"

int potega(int x){
	int i;
	int odp=1;
	for(i=0; i<x; i++)
		odp*=2;
	return odp;
}

void liniap( int *s, int *id, FILE *in, int c, char *z){ 
	int k=0;
	*z=fgetc(in);
	printf("%c",*z);
	while (*z!='\n' && *z!=EOF){
		/*if (k==7){
                        k=0;
                        (*id)++;
                }*/
		if (*z==' '){
			s[(*id)+k/7]+=potega(4*(k%7));
			//printf("\nId %d, Komórka %d - 0\n", (*id)+k/7, k%7);
		}
		//printf("\n----%d----\n", *id+k/7);
		*z=fgetc(in);
		if(*z=='\n')
			break;
		printf("%c",*z);
		*z=fgetc(in);
		printf("%c",*z);
		if(*z=='\n')
			break;
		if (*z==' '){
			s[(*id)+k/7]+=potega(2+4*(k%7));
			//printf("\nId %d, Komórka %d - 2\n", (*id)+k/7, k%7);
		}
		//printf("\n----%d----\n", *id+k/7);
		k++;
		*z=fgetc(in);
		printf("%c",*z);
		if(*z=='\n')
			break;
		*z=fgetc(in);
		printf("%c",*z);
	}
	//printf("\nnowaaaaa3333333333333\n");
	//(*id)++;

}

void linianp( int *s, int *id, FILE *in, int c, int blocks, char *z){
	int k=0, kp=0, kn=0;
	int idd=*id;
	*z=fgetc(in);
	printf("%c",*z);
	*z=fgetc(in);
	printf("%c",*z);
	while (*z!='\n' && *z!=EOF){
		/*if (k==7){
                        k=0;
                        (*id)++;
			printf("\n----%d----\n", *id);
                }*/
		if (*z==' '){
			s[(*id)+kp/7-blocks]+=potega(3+4*(kp%7));
			//printf("\nId %d, Komórka %d - 3\n", (*id)+kp/7-blocks, kp%7);
		}
		kp++;
		*z=fgetc(in);
		printf("%c",*z);
		*z=fgetc(in);
		printf("%c",*z);
		//printf("%d\n", *id);
		if (*z=='\n' || *z==EOF)
			break;
		if(*z==' '){
			s[(*id)+k/7]+=potega(1+4*(k%7));
			//printf("\nId %d, Komórka %d - 1\n", (*id)+k/7, k%7);
		}
		k++;
		*z=fgetc(in);
		printf("%c",*z);
		*z=fgetc(in);
		printf("%c",*z);
	}
	k=0;
	//(*id)=idd;
	if (*z!=EOF){
		*z=fgetc(in);
		printf("%c",*z);
		*z=fgetc(in);
		printf("%c",*z);
		*z=fgetc(in);
		printf("%c",*z);
	}

	while (*z!='\n' && *z!=EOF){
		/*if (k==7){
                        k=0;
                        (*id)++;
			printf("\n----%d----\n", *id);
                }*/
		if(*z==' '){
			s[(*id)+k/7]+=potega(4*(k%7));
			//printf("\nId %d, Komórka %d - 0\n", (*id)+k/7, k%7);
		}
		//printf("\n----%d----\n", *id+k/7);
		*z=fgetc(in);
		printf("%c",*z);
		if (*z=='\n' || *z==EOF)
			break;
		*z=fgetc(in);
		printf("%c",*z);
		if (*z=='\n' || *z==EOF)
			break;
		if(*z==' '){
			s[(*id)+k/7]+=potega(2+4*(k%7));
			//printf("\nId %d, Komórka %d - 2\n", (*id)+k/7, k%7);
		}
		k++;
		*z=fgetc(in);
		printf("%c",*z);
		if (*z=='\n' || *z==EOF)
			break;
		*z=fgetc(in);
		printf("%c",*z);
	}
	if (*z!=EOF){
		*z=fgetc(in);
		printf("%c",*z);
		k=0;
		//(*id)=idd;
		kn=0;
		*z=fgetc(in);
		printf("%c",*z);
	}
	while (*z!='\n' && *z!=EOF){
		/*if (k==7){
                        k=0;
                        (*id)++;
			printf("\n----%d----\n", *id);
                }*/
		if (*z==' '){
			s[(*id)+kn/7+blocks]+=potega(1+4*(kn%7));
			//printf("\nId %d, Komórka %d - 1\n", (*id)+kn/7+blocks, kn%7);
		}
		kn++;
		*z=fgetc(in);
		printf("%c",*z);
		*z=fgetc(in);
		printf("%c",*z);
		if (*z=='\n' || *z==EOF)
			break;
		if (*z==' '){
			s[(*id)+k/7]+=potega(3+4*(k%7));
			//printf("\nId %d, Komórka %d - 3\n", (*id)+k/7, k%7);
		}
		k++;
		*z=fgetc(in);
		printf("%c",*z);
		*z=fgetc(in);
		printf("%c",*z);
	}
	//(*id)++;
}

void read( int *s, FILE *in, int r, int c, int blocks){
	int rr=0, cc=0;
	char p='0';
	int pom=7;
	char z;
	int id=0;
	z='a';
	if(c%2==0)
		p='1';
	while (rr<r){// liczymy odczytane rzędy
		linianp(s, &id, in, c, blocks, &z);
		rr++;
		/*if (id%blocks!=0)
			id=blocks*rr;*/
		id+=blocks;
		if (cc==c)
			break;
		liniap(s, &id, in, c, &z);
		rr++;
		/*if (id%blocks!=0)
			id=blocks*rr;*/
		id+=blocks;
	}	
}

int bin( int x){
	long int i=1;
	int b=0;
	while (x!=0){
		b+=x%2*i;
		x/=2;
		i*=10;
	}
	return b;
}
