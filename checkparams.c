#include "checkparams.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void checkparams(params_str* params, int argc, char** argv){
	int option;
	params->inputFileName = argv[1];
	
	while ((option = getopt(argc, argv, "f:h")) != -1){

	switch(option) {
	case 'f':
		params->outputToFile = true;
		params->fileName = optarg;
		break;
	case 'h':
		params->help = true;
		break;
	case '?':
		printf("niewiadomy parametr: %c\n", optopt);
		break;
	}
	
}
}
