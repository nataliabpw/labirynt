#ifndef READMAZE_H
#define READMAZE_H
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
int checkinput(char* filename);

void read(maze* m);

int checkpassage(int node_number, int direction, maze* m);


#endif
