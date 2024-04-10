#ifndef _PRINTPATH_H_
#define _PRINTPATH_H_

#include "path.h"

int location( int * predecessors, int node_number);
int predecessor_number( int node_number, int location, int columns);
void print_pathh( path * p, int columns, int begin, int end);

#endif

