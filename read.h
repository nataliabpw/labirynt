#ifndef _READ_H_
#define _READ_H_

#include <stdio.h>
int potega(int x);
void liniap( int *s, int *id, FILE *in, int c, char *z);
void linianp( int *s, int *id, FILE *in, int c, int blocks, char *z);
void read( int *s, FILE *in, int r, int c, int blocks);
int bin(int x);

#endif
