#ifndef CHECKPARAMS_H
#define CHECKPARAMS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct{
	bool outputToFile;
	char* fileName;
	char* inputFileName;
	bool help;
} params_str;
void checkparams(params_str* params, int argc, char** argv);
#endif
