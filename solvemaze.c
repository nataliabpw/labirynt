#include "maze.h"
#include "path.h"
#include "readmaze.h"
#include "solvemaze.h"
#include <stdio.h>
#include <stdlib.h>

void path_init(path * p, maze * m){
	int v_len;
	int pred_len;
	int q_max_len;
	int i;

	v_len = (m->columns)*(m->rows) / N_VISITED + 1;
	pred_len = (m->columns)*(m->rows) / N_PREDECESSORS + 1;
	q_max_len = m->columns > m->rows ? m->columns * 3 : m->rows * 3;

	p->visited = calloc(v_len, sizeof(int));
	p->predecessors = calloc(pred_len, sizeof(int));
	p->queue = malloc(q_max_len * sizeof(int));

	for (i=0; i<q_max_len; i++)
		p->queue[i]=-1;
}

int power_of_two( int power){
	int x=1;
	int p=0;
	while (p < power){
		x*=2;
		p++;
	}
	return x;
}

void mark_as_visited( int node_number, int * visited){
	int v_id = node_number / N_VISITED;
	int power = node_number % N_VISITED;
	visited[v_id] += power_of_two(power);
}

int check_if_visited( int node_number, int * visited){
	int v_id = node_number / N_VISITED;
	int power = node_number % N_VISITED;
	if (visited[v_id] % power_of_two(power + 1) >= power_of_two(power))
		return 1;
	return 0;
}

void set_predecessor( int node_number, int direction, int * predecessors){
	int p_id = node_number / N_PREDECESSORS;
	int power = (node_number % N_PREDECESSORS) * 2;
	if (direction == DIRECTION_TOP || direction == DIRECTION_BOTTOM)
		predecessors[p_id] += power_of_two(power);
	if (direction == DIRECTION_RIGHT || direction == DIRECTION_BOTTOM)
		predecessors[p_id] += power_of_two(power+1);
}

int solve( maze * m, path * p){
	int direction;
	int i, j;
	int curr_node;
	int next_node;
	int q_len;
	int solved = 0;
	m->begin--;
	m->end--;
	
	//inicjacja path
	path_init(p, m);

	p->queue[0]=m->end;
	mark_as_visited( m->end, p->visited);
	q_len=1;

	while (q_len > 0){
		curr_node = p->queue[0];
		for (i=DIRECTION_LEFT; i<=DIRECTION_BOTTOM; i++){ //położenie next_node względem curr_node
			if (checkpassage(curr_node+1, i, m) == PASSAGE_CONST){
				if (i==DIRECTION_LEFT)
					next_node = curr_node - 1;
				if (i==DIRECTION_TOP)
					next_node = curr_node - (m->columns);
				if (i==DIRECTION_RIGHT)
					next_node = curr_node + 1;
				if (i==DIRECTION_BOTTOM)
					next_node = curr_node + (m->columns);
				if (next_node > (m->end))
					continue;
				direction = 20 + (i+2)%4; //położenie poprzednika(curr_node) względem next_node
				if (check_if_visited( next_node, p->visited) == 0){
					p->queue[q_len++] = next_node;
					mark_as_visited( next_node, p->visited);
					set_predecessor( next_node, direction, p->predecessors);
				}
				if (next_node == (m->begin)){
					solved = 1;
					break;
				}
			}
		}
		if (next_node == (m->begin)){
			solved = 1;
			break;
		}

		//usun queue[0]
		for (i=0; i<q_len; i++)
			p->queue[i]=p->queue[i+1];
		q_len--;
		
	}
	free(p->queue);
	free(p->visited);
	if (solved == 0)
		return 1;
	return 0;
}
