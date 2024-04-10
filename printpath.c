#include <stdio.h>
#include "path.h"
#include "printpath.h"

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

void print_pathh( path * p, int columns, int begin, int end){
	int curr_node = begin;
	int next_node;
	int pom;
	int node_count = 0;
	int curr_direction;
	int next_direction;
	int i;
	int print_count = 0;
	int czy_print=0;

	curr_direction = location(p->predecessors, curr_node);
	next_node = predecessor_number(curr_node, curr_direction, columns);
	curr_node=next_node;
	node_count++;
	print_count++;

	while (curr_node!=end){
		next_direction=location(p->predecessors, curr_node);
		next_node = predecessor_number(curr_node, next_direction, columns);
		print_count++;
		czy_print=0;
		if (curr_direction!=next_direction){
			czy_print=1;
			printf("FORWARD  %d\n", print_count-1);
			if (next_direction==curr_direction+1 || next_direction==curr_direction-3)
				printf("TURNRIGHT\n");
			if (next_direction==curr_direction-1 || next_direction==curr_direction+3)
				printf("TURNLEFT\n");
			print_count=1;
		}
		curr_direction=next_direction;
		curr_node=next_node;
		node_count++;
	}
	if (czy_print==0)
		printf("FORWARD %d\n", print_count);
}
