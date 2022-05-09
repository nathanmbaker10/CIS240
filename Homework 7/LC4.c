#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LC4.h"
#include "Instructions.h"


char* fourHexDigitRepresentation(int n) {
	char *output = (char*) calloc(5, sizeof(char));
	int nCopy = n;

	int i;
	int currentDigit;
	for(i = 0; i < 4; i++) {
		currentDigit = nCopy % 16;
		if(currentDigit >= 10) {
			
			output[3 - i] = currentDigit + 'A' - 10;
		} else {
			output[3 - i] = currentDigit + '0';
		}
		nCopy /= 16;
	}

	output[4] = 0;


	return output;
}

void writeDATALine(FILE* outputFile, int memoryArray[], int address) {
	// if(outputFile == NULL){
	// 	printf("NULL filePointer\n",);
	// }
	fprintf(outputFile, "%04X : %04X\n", address, memoryArray[address]);
}


void writeCodeLine(FILE* outputFile, int memoryArray[], int address) {
	// char[] stringToWrite = determineStringLine(memoryArray, address);
	char* instructionString = getInstructionsString(memoryArray[address]);

	fprintf(outputFile, "%04X : %04X -> %s\n", address, memoryArray[address], instructionString);
	free(instructionString);	

	
}

void writeToOutputFile(char* outputFileString, int memoryArray[]) {
	//TODO: Open output file for writing here
	
	
	FILE* outputFile = fopen(outputFileString, "w");

	int i;
	for(i = 0; i < 65536; i++) {
		if(memoryArray[i] == 0) {
			continue;
		} else if((i <= 0x1fff) || (i >= 0x8000 && i <= 0x9fff)) {
			
			writeCodeLine(outputFile, memoryArray, i);
		} else {
			writeDATALine(outputFile, memoryArray, i);
		}
	}
	fclose(outputFile);
}