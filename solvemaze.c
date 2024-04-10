#include "maze.h"
#include "path.h"
#include <stdio.h>

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

}
