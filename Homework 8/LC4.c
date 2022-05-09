#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LC4.h"
#include "Instructions.h"
#include "Execute.h"

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    else if (exp % 2)
        return base * power(base, exp - 1);
    else {
        int temp = power(base, exp / 2);
        return temp * temp;
    }
}

int grabSectionOfInstruction(int instruction, int msb, int lsb) {
	
	int rangeSize = msb - lsb + 1;

	unsigned int mask = power(2, rangeSize) - 1;

	mask = mask << lsb;

	unsigned int output = instruction & mask;

	output = output >> lsb;

	return output;
}


int signExtendInt(int n, int numBits) {

	int sign = grabSectionOfInstruction(n, numBits - 1, numBits - 1);

	if (sign) {
		int mask = power(2, numBits) - 1;

		int output = n ^ mask;
		output++;

		output = output & mask;
		return -1 * output;
	} else {
		return n;	
	}

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


void beginTrace(char* outputFileString, int memoryArray[]) {
	MachineState* machine = newMachine();

	FILE* outputFile = fopen(outputFileString, "w");

	while(machine->PC != 0x80ff) {
		int currentPC = machine->PC;
		int priveledgeMode = machine->priveledge;

		if((currentPC >= 0x2000 && currentPC <= 0x7FFF) || currentPC >=0xFFFF) {
			printf("ERROR: Executing code from DATA section");

			exit(1);
		} else if(currentPC >= 0x8000 && !priveledgeMode) {
			printf("ERROR: OS Priveledge not granted");

			exit(1);
		}


		char* lineToPrint = runInstructionsString(machine, memoryArray[currentPC], memoryArray);
		if(lineToPrint == NULL) {
			printf("ERROR: attempting to load or store data from code section OR not in proper priveledge mode.");

			exit(1);			
		}
		fprintf(outputFile, "%s", lineToPrint);
		free(lineToPrint);
	}
	fclose(outputFile);
	free(machine);

}