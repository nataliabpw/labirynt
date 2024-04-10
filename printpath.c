#include <stdio.h>
#include "path.h"
#include "maze.h"

int location( int * predecessors, int node_number){
	int p_id = node_number / 15;
	int bit = (node_number % 15) * 2;
	int l = 0;
	if ((predecessors[p_id] & (1 << bit)) != 0) //sprawdza bit
		l++;
	if ((predecessors[p_id] & (1 << (bit + 1))) != 0) //sprawdza bit + 1
		l+=2;
	return l;
}

int predecessor_number( int node_number, int location, int columns){
	if (location == 0)
		return node_number - 1;
	if (location == 1)
		return node_number - columns;
	if (location == 2)
		return node_number + 1;
	if (location == 3)
		return node_number + columns;
}