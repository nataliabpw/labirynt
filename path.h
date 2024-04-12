#ifndef _PATH_H_
#define _PATH_H_
#define N_VISITED 30 // nodes in one block (visited)
#define N_PREDECESSORS 15 // nodes in one block (predecessors)

typedef struct {
	int * predecessors;// wektor poprzedników
	int * visited;// wektor odwiedzonych komórek
	int * queue;// kolejka
} path;

#endif
