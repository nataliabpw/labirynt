#ifndef _PATH_H_
#define _PATH_H_

typedef struct {
	int * predecessors;// wektor poprzedników
	int * visited;// wektor odwiedzonych komórek
	int * queue;// kolejka
} path;

#endif
