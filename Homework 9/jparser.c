#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "ctype.h"

#include "token.h"


void freeStuff(char* realFile, char* actualJ, char* ASMfinal, char* lineCurrent,
	char* inputToken) {
	free(realFile);
	free(actualJ);
	free(ASMfinal);
	free(lineCurrent);
	free(inputToken);
}


int main(int argc, char** argv) {
	FILE *input;

	token *inputToken;

	FILE *outputFile;


	char* filename = argv[1];

	FILE* src_file = fopen(filename, "r");

	char* output = filename + strlen(filename)+3;
	strcpy(output, filename);
	output[strlen(output)-1] = '\0';
	strcat(output, "asm");
	
	outputFile = fopen(output , "w");
	

	char *ASMfinal = malloc(sizeof(char)* 50);

	char *actualJ = malloc(sizeof(char) * 250);

	char *realFile = malloc(sizeof(char) * 2 + strlen(argv[1]));
	
	strcpy(actualJ, argv[1]);

	strcpy(ASMfinal, ".asm\0");
	strcpy(realFile, "");

	

	



	input = fopen(argv[1], "r");

	char *tokenCurrent;
	
	char *lineCurrent = malloc(sizeof(char) * 512);
	int loopCounter = 0;

	

	while(!feof(input)) 

	{	
		
		loopCounter++;
		fgets(lineCurrent , 256, input);

		
		

		tokenCurrent = strtok(lineCurrent , "\t\n\r ");	
		

		while(tokenCurrent != NULL) {
			if(tokenCurrent[0] == ';') {
				break;
			}



			inputToken = malloc(sizeof(*inputToken));

			
			if(functionMain(tokenCurrent, inputToken) == 1) {
				printf("got 1\n");
				free(inputToken);
				free(realFile);
				free(ASMfinal);
				free(lineCurrent);
				free(actualJ);				
				exit(0);
				return 0;
			}
			
			
			if(createMLFor(outputFile, inputToken) == 1) {
				return 0;
			}

			tokenCurrent = strtok(NULL, "\t\n\r ");


			free(inputToken);
			
		}

		if(lineCurrent == NULL) {
			break;
		}

		

	}

	free(lineCurrent);

	free(actualJ);
	free(realFile);
	free(ASMfinal);

	fclose(outputFile);
	fclose(input);

	return 0;


}