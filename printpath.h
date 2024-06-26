#ifndef _PRINTPATH_H_
#define _PRINTPATH_H_

#include <stdio.h>
#include "path.h"
#include "maze.h"

int location( int * predecessors, int node_number);
int predecessor_number( int node_number, int location, int columns);
void turn( int curr_direction, int next_direction, FILE * out);
void print_path( path * p, maze * m, FILE * out);

#endif

