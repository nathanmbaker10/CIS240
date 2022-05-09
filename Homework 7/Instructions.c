#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Instructions.h"


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


char* getRTIString() {
	char* output = malloc(20 * sizeof(char)); 
	sprintf(output, "RTI");

	
	return output;


	
}

char* getTrapString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int unsignedOffset = grabSectionOfInstruction(instruction, 7, 0);
	sprintf(output, "TRAP #%d", unsignedOffset);
	
	return output;


}

char* getHiConstString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int Rd = grabSectionOfInstruction(instruction, 11, 9);

	int unsignedOffSetImmediate = grabSectionOfInstruction(instruction, 7, 0);

	sprintf(output, "HICONST R%d, #%d", Rd, unsignedOffSetImmediate);
	
	return output;
}

char* getCONSTString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	

	int offSetImmediate = grabSectionOfInstruction(instruction, 8, 0);
	int offSet = signExtendInt(offSetImmediate, 9);

	sprintf(output, "CONST R%d, #%d", Rd, offSet);
	
	return output;


}

char* getSTRString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int Rt = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);

	int offSetImmediate = grabSectionOfInstruction(instruction, 5, 0);
	int offSet = signExtendInt(offSetImmediate, 6);

	sprintf(output, "STR R%d, R%d, #%d", Rt, Rs, offSet);

	
	return output;


}

char* getLDRString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 

	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);

	int offSetImmediate = grabSectionOfInstruction(instruction, 5, 0);

	int offSet = signExtendInt(offSetImmediate, 6);

	sprintf(output, "LDR R%d, R%d, #%d", Rd, Rs, offSet);

	
	return output;
}


char* getJumpString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int subOpCode = grabSectionOfInstruction(instruction, 11, 11);
	switch(subOpCode) {
		int Rs;
		int offSetImmediate;
		int offSet;
		case 0:
			Rs = grabSectionOfInstruction(instruction, 8, 6);
			sprintf(output, "JMPR R%d", Rs);
			break;
		case 1:
			offSetImmediate = grabSectionOfInstruction(instruction, 10, 0);
			offSet = signExtendInt(offSetImmediate, 11);
			sprintf(output, "JMP #%d", offSet);
			break;
		default:
			sprintf(output, "INVALID COMMAND");
			break;
	}
	
	return output;
}


char* getJString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int subOpCode = grabSectionOfInstruction(instruction, 11, 11);
	switch(subOpCode) {
		int Rs;
		int offSetImmediate;
		int offSet;
		case 0:
			Rs = grabSectionOfInstruction(instruction, 8, 6);
			sprintf(output, "JSRR R%d", Rs);
			break;
		case 1:
			offSetImmediate = grabSectionOfInstruction(instruction, 10, 0);
			offSet = signExtendInt(offSetImmediate, 11);
			sprintf(output, "JSR #%d", offSet);
			break;
		default:
			sprintf(output, "INVALID COMMAND");
			break;
	}
	
	return output;

}

char* getModString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);
	int Rt = grabSectionOfInstruction(instruction, 2, 0);

	sprintf(output, "MOD R%d, R%d, R%d", Rd, Rs, Rt);
	
	return output;
}

char* getShiftString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);

	int unsignedOffset = grabSectionOfInstruction(instruction, 3, 0);

	int opCode = grabSectionOfInstruction(instruction, 5, 4);

	switch(opCode){
		case 0:
			sprintf(output, "SLL R%d, R%d, #%d", Rd, Rs, unsignedOffset);
			break;
		case 1:
			sprintf(output, "SRA R%d, R%d, #%d", Rd, Rs, unsignedOffset);
			break;
		case 2:
			sprintf(output, "SRL R%d, R%d, #%d", Rd, Rs, unsignedOffset);
			break;
		case 3:
			output = getModString(instruction);
			break;
		default:
			sprintf(output, "INVALID COMMAND");
			break;
	}
	
	return output;
}



char* getCompareString(int instruction) {
	char* output = malloc(20 * sizeof(char)); 
	int Rs = grabSectionOfInstruction(instruction, 11, 9);
	int Rt = grabSectionOfInstruction(instruction, 2, 0);

	int subOpCode = grabSectionOfInstruction(instruction, 8, 7);

	switch(subOpCode){
		int offSetImmediate;
		int offSet;
		int unsignedOffset;
		case 0:
			sprintf(output, "CMP R%d, R%d", Rs, Rt);
			break;
		case 1:
			sprintf(output, "CMPU R%d, R%d", Rs, Rt);
			break;
		case 2:
			offSetImmediate = grabSectionOfInstruction(instruction, 6, 0);
			offSet = signExtendInt(offSetImmediate, 7);
			sprintf(output, "CMPI R%d, #%d", Rs, offSet);
			break;
		case 3:
			unsignedOffset = grabSectionOfInstruction(instruction, 6, 0);
			sprintf(output, "CMPIU R%d, #%d", Rs, unsignedOffset);
		default:
			sprintf(output, "INVALID COMMAND");
			break;
	}
	
	return output;
}


char* getOperatorString(int instruction) {
	int immediateAdd = grabSectionOfInstruction(instruction, 5, 5);
	char* output = malloc(20 * sizeof(char)); 
	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);


	if(immediateAdd) {
		int offSetImmediate = grabSectionOfInstruction(instruction, 4, 0);
		int offSet = signExtendInt(offSetImmediate, 5);

		sprintf(output, "AND R%d, R%d, #%d", Rd, Rs, offSet);
	} else {
		int Rt = grabSectionOfInstruction(instruction, 2, 0);
		int subOpCode = grabSectionOfInstruction(instruction, 4, 3);

		switch(subOpCode) {
			case 0:
				sprintf(output, "AND R%d, R%d, R%d", Rd, Rs, Rt);
				break;
			case 1:
				sprintf(output, "NOT R%d, R%d", Rd, Rs);
				break;
			case 2:
				sprintf(output, "OR R%d, R%d, R%d", Rd, Rs, Rt);
				break;
			case 3:
				sprintf(output, "XOR R%d, R%d, R%d", Rd, Rs, Rt);
				break;
			default:
				sprintf(output, "INVALID INSTRUCTION");
				break;
		}
	}
	
	return output;
}


char* getArithmeticString(int instruction) {
	int immediateAdd = grabSectionOfInstruction(instruction, 5, 5);
	char* output = malloc(20 * sizeof(char)); 
	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);

	if(immediateAdd) {
		int offSetImmediate = grabSectionOfInstruction(instruction, 4, 0);
		
		int offSet = signExtendInt(offSetImmediate, 5);


		sprintf(output, "ADD R%d, R%d, #%d", Rd, Rs, offSet);
	} else {
		int Rt = grabSectionOfInstruction(instruction, 2, 0);
		int subOpCode = grabSectionOfInstruction(instruction, 4, 3);

		

		switch(subOpCode) {
			case 0:
				sprintf(output, "ADD R%d, R%d, R%d", Rd, Rs, Rt);
				break;
			case 1:
				sprintf(output, "MUL R%d, R%d, R%d", Rd, Rs, Rt);
				break;
			case 2:
				sprintf(output, "SUB R%d, R%d, R%d", Rd, Rs, Rt);
				break;
			case 3:
				sprintf(output, "DIV R%d, R%d, R%d", Rd, Rs, Rt);
				break;
			default:
				break;
		}
	}
	
	return output;

}

char* getBranchString(int instruction) {
	int offSetImmediate = grabSectionOfInstruction(instruction, 8, 0);
	int offSet = signExtendInt(offSetImmediate, 9);

	int branchDeterminer = grabSectionOfInstruction(instruction, 11, 9);
	

	char *output = malloc(20 * sizeof(char));
	switch(branchDeterminer) {
		case 0:
			sprintf(output, "NOP");
			break;
		case 1:
			sprintf(output, "BRp #%d", offSet);
			break;
		case 2 : 
			sprintf(output, "BRz #%d", offSet);
			break;
		case 3 : 
			sprintf(output, "BRzp #%d", offSet);
			break;
		case 4 : 
			sprintf(output, "BRn #%d", offSet);
			break;
		case 5 : 
			sprintf(output, "BRnp #%d", offSet);
			break;
		case 6 : 
			sprintf(output, "BRnz #%d", offSet);
			break;
		case 7 : 
			sprintf(output, "BRnzp #%d", offSet);
			break;
		default:
			sprintf(output, "INVALID INSTRUCTION");
			break;
	}

	
	return output;
}

char* getInstructionsString(int instruction) {
	

	int opCode = grabSectionOfInstruction(instruction, 15, 12);
	
	char* output = NULL; 
	switch (opCode) {
		case 0:
			output = getBranchString(instruction);
			break;
		case 1:
			output = getArithmeticString(instruction);
			break;
		case 10:
			output = getShiftString(instruction);
			break;
		case 5:
			output = getOperatorString(instruction);
			break;
		case 6:
			output = getLDRString(instruction);
			break;
		case 7:
			output = getSTRString(instruction);
			break;
		case 9:
			output = getCONSTString(instruction);
			break;
		case 13:
			output = getHiConstString(instruction);
			break;
		case 2:
			output = getCompareString(instruction);
			break;
		case 4:
			output = getJString(instruction);
			break;
		case 12:
			output = getJumpString(instruction);
			break;
		case 15:
			output = getTrapString(instruction);
			break;
		case 8:
			output = getRTIString();
			break;
		default:
			sprintf(output, "INVALID INSTRUCTION");
	}
	
	return output;
}