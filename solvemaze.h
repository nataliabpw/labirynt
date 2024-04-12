#ifndef _SOLVE_MAZE_H_
#define _SOLVE_MAZE_H_

#include "maze.h"
#include "path.h"
#include <stdio.h>

void path_init(path * p, maze * m);
int power_of_two( int power);
void mark_as_visited( int node_number, int * visited);
int check_if_visited( int node_number, int * visited);
void set_predecessor( int node_number, int direction, int * predecessors);
void solve( maze * m, path * p);

#endif
