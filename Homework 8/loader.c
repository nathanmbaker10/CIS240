#include<stdio.h>
#include<stdlib.h>
#include "parser.h"
#include "LC4.h"

int main(int argc, char *argv[]) {
	int lc4Memory[65536] = {0};
	FILE* currentFile;

	if(argc <= 2) {
		printf("ERROR: At least one input file should be specified\n");
	} else {
		int i;
		for(i = 2; i < argc; i++) {
			currentFile = fopen(argv[i], "rb");
			

			parseFile(lc4Memory, currentFile);
			fclose(currentFile);
		}


		beginTrace(argv[1], lc4Memory);
	}
}


