#include <stdio.h>
#include <stdlib.h>
#include "solvemaze.h"

punkt getPunkt(int number, int kolumny){
	
	int left, up, right, down;
	int temp = 1;
	int i;
	char s;
	FILE* in = fopen("p", "r");
	while(temp != number){
		fscanf(in, "%c", &s);
		if(s == '\n')
			temp++;
	}
	
	fscanf(in, "%c", &s);
	switch (s){
		case '0':
			left = -1;
			break;
		case '1':
			left = number-1;
			break;
	}
	fscanf(in, "%c", &s);
	switch (s){
		case '0':
			up = -1;
			break;
		case '1':
			up = number-kolumny;
			break;
	}
	fscanf(in, "%c", &s);
	switch (s){
		case '0':
			right = -1;
			break;
		case '1':
			right = number+1;
			break;
	}
	fscanf(in, "%c", &s);
	switch (s){
		case '0':
			down = -1;
			break;
		case '1':
			down = number+kolumny;
			break;
	}
	fclose(in);
	punkt p = {left, up, right, down};
	return p;

}

void dijkstra(){


	int wierszy = 6;
	int kolumny = 6;
	
	//pomiar grafu(ilość wierszchołków)
	int size = wierszy * kolumny;
	
	//UWAGA!!!
	int* d = malloc(size * sizeof(int));
	int* v = malloc(size * sizeof(int));
	
	int temp, minindex, min;
	int begin_index = 1; // 0 - początek
	
	int i;
	for(i = 0; i<=size; i++){
		v[i] = 1;
		d[i] = 10000;
	}
	d[begin_index] = 0;
	
	do{
	
		minindex = 10000;
		min = 10000;
		for(i = 0; i <=size; i++){
		
			if(((v[i]) == 1) && d[i]<min){
				min = d[i];
				minindex = i;
			}
		
		}
		if(minindex!=10000){
			
			punkt a = getPunkt(minindex, kolumny);
			if(a.left > 0){
				temp = min + 1;
				if(temp < d[a.left])
					d[a.left] = temp;
			}
			if(a.up > 0){
				temp = min + 1;
				if(temp < d[a.up])
					d[a.up] = temp;
			}
			if(a.right > 0){
				temp = min + 1;
				if(temp < d[a.right])
					d[a.right] = temp;
			}
			if(a.down > 0){
				temp = min + 1;
				if(temp < d[a.down])
					d[a.down] = temp;
			}
				
		v[minindex] = 0;
		}
	
	} while(minindex<10000);
	
	//!!!!!!
	int* ver = malloc(size *sizeof(int));
	int end = size;
	ver[0] = size;
	int k = 1;
	int weight = d[end];
	
	while(end != begin_index){
	
		punkt a = getPunkt(end, kolumny);
			if(a.left > 0){
				int temp = weight - 1;
				if(temp == d[a.left]){
					weight = temp;
					end = a.left;
					ver[k] = a.left;
					k++;
				}
				
			}
			if(a.up > 0){
				int temp = weight - 1;
				if(temp == d[a.up]){
					weight = temp;
					end = a.up;
					ver[k] = a.up;
					k++;
				}
			}
			if(a.right > 0){
				int temp = weight - 1;
				if(temp == d[a.right]){
					weight = temp;
					end = a.right;
					ver[k] = a.right;
					k++;
				}
			}
			if(a.down > 0){
				int temp = weight - 1;
				if(temp == d[a.down]){
					weight = temp;
					end = a.down;
					ver[k] = a.down;
					k++;
				}
			}
	
	}
	
	for (i = k-1; i>=0; i--){
		printf("%d ", ver[i]);
	}
	
	free(ver);
	free(d);
	free(v);

}
