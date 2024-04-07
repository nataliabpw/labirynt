#ifndef READFROMTXT_H
#define READFROMTXT_H
#include "maze.h"
#include <stdlib.h>
#include <stdio.h>
int checkinputTXT(maze* m);

void readTXT(maze* m);

int checkpassageTXT(int node_number, int direction, maze* m);
int node_byte(int node_number, maze* m);
int top_byte(int node_number, maze* m);
int bottom_byte(int node_number, maze* m);
#endif
