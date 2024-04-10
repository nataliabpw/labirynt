#include "maze.h"
#include "path.h"
#include "readmaze.h"
#include "solvemaze.h"
#include <stdio.h>
#include <stdlib.h>

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
	int v_id = node_number/30;
	int power = node_number%30;
	visited[v_id] += power_of_two(power);
}

int check_if_visited( int node_number, int * visited){
	int v_id = node_number/30;
	int power = node_number%30;
	if (visited[v_id] % power_of_two(power + 1) >= power_of_two(power))
		return 1;
	return 0;
}

void set_predecessor( int node_number, int direction, int * predecessors){
	int p_id = node_number/15;
	int power = (node_number%15) * 2;
	if (direction == 1 || direction == 3)
		predecessors[p_id] += power_of_two(power);
	if (direction == 2 || direction == 3)
		predecessors[p_id] += power_of_two(power+1);
}

void solve( maze * m, path * p){
	int location;
	int i, j;
	int curr_node;
	int next_node;
	int q_len;
	int q_max_len;
	int v_len;
	int pred_len;
	m->begin--;
	m->end--;
	//inicjacja path
	v_len = (m->columns)*(m->rows)/30 + 1;
	p->visited = calloc(v_len, sizeof(int));
	pred_len = (m->columns)*(m->rows)/15 + 1;
	p->predecessors = calloc(pred_len, sizeof(int));
	q_max_len = (m->columns + m->rows)/2 + 2;
	p->queue = malloc(q_max_len * sizeof(int));
	
	for (i=0; i<q_max_len; i++)
		p->queue[i]=-1;

	p->queue[0]=m->end;
	mark_as_visited( m->end, p->visited);
	q_len=1;

	while (q_len > 0){
		curr_node = p->queue[0];
		for (i=0; i<4; i++){ //i - położenie next_node względem curr_node
			printf("node: %d dir: %d\n", curr_node+1, i+20);
			if (checkpassage(curr_node+1, i+20, m) == 10){
				if (curr_node==m->end && i==2)
					continue;
				if (curr_node==m->begin && i==0)
					continue;
				printf("ok\n");
				if (i==0)
					next_node = curr_node - 1;
				if (i==1)
					next_node = curr_node - (m->columns);
				if (i==2)
					next_node = curr_node + 1;
				if (i==3)
					next_node = curr_node + (m->columns);
				location = (i+2)%4; //położenie poprzednika(curr_node) względem next_node
				if (check_if_visited( next_node, p->visited) == 0){
					p->queue[q_len++] = next_node;
					mark_as_visited( next_node, p->visited);
					set_predecessor( next_node, location, p->predecessors);
				}
				if (next_node == (m->begin))
					break;
			}
		}
		if (next_node == (m->begin))
			break;

		//usun queue[0]
		for (i=0; i<q_len; i++)
			p->queue[i]=p->queue[i+1];
		q_len--;
	}				
	free(p->queue);
}
