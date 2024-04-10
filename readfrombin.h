#ifndef READFROMBIN_H
#define READFROMBIN_H
#include "maze.h"
#include <stdlib.h>
#include <stdio.h>
int checkinputBIN(maze* m);

void readBIN(maze* m);

int checkpassageBIN(int node_number, int direction, maze* m);

#endif
