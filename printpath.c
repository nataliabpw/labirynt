#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include "printpath.h"
#include "maze.h"

int direction( int * predecessors, int node_number){
	int p_id = node_number / N_PREDECESSORS;
	int bit = (node_number % N_PREDECESSORS) * 2;
	int d = DIRECTION_LEFT;
	if ((predecessors[p_id] & (1 << bit)) != 0) //sprawdza bit
		d++;
	if ((predecessors[p_id] & (1 << (bit + 1))) != 0) //sprawdza bit + 1
		d+=2;
	return d;
}

int predecessor_number( int node_number, int direction, int columns){
	if (direction == DIRECTION_LEFT)
		return node_number - 1;
	if (direction == DIRECTION_TOP)
		return node_number - columns;
	if (direction == DIRECTION_RIGHT)
		return node_number + 1;
	if (direction == DIRECTION_BOTTOM)
		return node_number + columns;
}

int begin_direction( int columns, int begin){
	int c = begin % columns;
	int r = begin / columns;
	if (c == 0 )
		return DIRECTION_RIGHT;
	if (r == 0 )
		return DIRECTION_BOTTOM;
}

void turn( int curr_direction, int next_direction, FILE * out){
	if (next_direction == curr_direction + 1 || next_direction == curr_direction - 3)
		fprintf(out, "TURNRIGHT\n");
	if (next_direction == curr_direction - 1 || next_direction == curr_direction + 3)
		fprintf(out, "TURNLEFT\n");
}

void print_path( path * p, maze * m, FILE * out){
	int curr_node = m->begin;
	int next_node;
	int default_direction = begin_direction( m->columns, m->begin);
	int curr_direction = default_direction;
	int next_direction;
	int print_count = 1;
	int i;

	fprintf(out, "START\n");
	next_direction = direction(p->predecessors, curr_node);
	if (curr_direction != next_direction){
		fprintf(out,"FORWARD %d\n", print_count);
		turn(curr_direction, next_direction, out);
		print_count = 0;
	}
	curr_direction = next_direction;
	next_node = predecessor_number(curr_node, curr_direction, m->columns);
	print_count++;
	curr_node = next_node;

	while (curr_node != m->end){
		next_direction = direction(p->predecessors, curr_node);
		next_node = predecessor_number(curr_node, next_direction, m->columns);
		print_count++;
		if (curr_direction != next_direction){
			fprintf(out, "FORWARD %d\n", print_count - 1);
			turn(curr_direction, next_direction, out);
			print_count = 1;
		}
		curr_direction = next_direction;
		curr_node = next_node;
	}
	next_direction = default_direction;
	print_count++;
	if (curr_direction != next_direction){
		fprintf(out, "FORWARD %d\n", print_count - 1);
		turn(curr_direction, next_direction, out);
		print_count = 1;
	}
	fprintf(out, "FORWARD %d\n", print_count);
	fprintf(out, "STOP\n");
	free(p->predecessors);
}
