#ifndef SOLVEMAZE_H
#define SOLVEMAZE_H

typedef struct {
	int left;
	int up;
	int right;
	int down; 
} punkt;
void dijkstra();
punkt getPunkt(int number, int kolumny);
#endif
