#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "LC4.h"
#include "Execute.h"

int grabRegisterValue(MachineState* machine, int reg) {
	switch(reg) {
		case 0:
			return signExtendInt(machine->R0, 16);
			break;
		case 1:
			return signExtendInt(machine->R1, 16);
			break;
		case 2:
			return signExtendInt(machine->R2, 16);
			break;
		case 3:
			return signExtendInt(machine->R3, 16);
			break;
		case 4:
			return signExtendInt(machine->R4, 16);
			break;
		case 5:
			return signExtendInt(machine->R5, 16);
			break;
		case 6:
			return signExtendInt(machine->R6, 16);
			break;
		case 7:
			return signExtendInt(machine->R7, 16);
			break;
		default:
			return -1;
			break;

	} 
}

int grabUnsignedRegisterValue(MachineState* machine, int reg) {
	switch(reg) {
		case 0:
			return machine->R0;
			break;
		case 1:
			return machine->R1;
			break;
		case 2:
			return machine->R2;
			break;
		case 3:
			return machine->R3;
			break;
		case 4:
			return machine->R4;
			break;
		case 5:
			return machine->R5;
			break;
		case 6:
			return machine->R6;
			break;
		case 7:
			return machine->R7;
			break;
		default:
			return -1;
			break;

	} 
}

void setRegisterValue(MachineState* machine, int reg, unsigned int val) {
	switch(reg) {
		case 0:
			machine->R0 = val;
			break;
		case 1:
			machine->R1 = val;
			break;
		case 2:
			machine->R2 = val;
			break;
		case 3:
			machine->R3 = val;
			break;
		case 4:
			machine->R4 = val;
			break;
		case 5:
			machine->R5 = val;
			break;
		case 6:
			machine->R6 = val;
			break;
		case 7:
			machine->R7 = val;
			break;
		default:
			break;
	} 
}

int nzpValueInt(MachineState* machine, int value) {
	if(value < 0) {
		machine->NZP = 4;
		return 4;
	} else if (value == 0) {
		machine->NZP = 2;
		return 2;
	} else {
		machine->NZP = 1;
		return 1;
	}
}

int nzpValueFrom(MachineState* machine, int reg) {
	int regval = grabRegisterValue(machine, reg);
	return nzpValueInt(machine, regval);
}




MachineState* newMachine() {
	MachineState machine;
	machine.priveledge = 1;
	machine.NZP = 2;
	machine.PC = 0x8200;
	machine.R0 = 0;
	machine.R1 = 0;
	machine.R2 = 0;
	machine.R3 = 0;
	machine.R4 = 0;
	machine.R5 = 0;
	machine.R6 = 0;
	machine.R7 = 0;


	MachineState* output = (MachineState*)malloc(sizeof(machine));

	*output = machine;

	return output;
} 


char* binaryRepresentation(int instruction) {
	char string[] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0'};
	int instructionCopy = instruction;

	for(int i = 0; i < 16; i++) {
		int currentDigit = instructionCopy % 2;
		string[15 - i] = currentDigit + '0';
		instructionCopy /= 2;
	}

	char *output = (char*)malloc(sizeof(char) * 17);
	sprintf(output, "%s", string);

	return output;
}


TraceStruct* newTraceStruct(int pc, char* binaryInstruction, int regfilewe, int rd, int rd_val, int nzpwe, int nzpval, 
							int datawe, int dataaddr, int dataval) {
	TraceStruct object;
	object.PC = pc;

	object.instruction = binaryInstruction;
	sprintf(object.instruction, "%s", binaryInstruction);
	
	
	object.regFile_we = regfilewe;
	
	object.Rd = rd;
	
	object.Rd_val = rd_val;
	
	object.NZP_we = nzpwe;
	
	object.NZP_val = nzpval;
	
	object.data_we = datawe;
	
	object.data_addr = dataaddr;
	
	object.data_val = dataval;



	TraceStruct *output = (TraceStruct*)malloc(sizeof(object));


	*output = object;


	return output;
}


char* newLineFromTrace(TraceStruct* trace) {
	char* output = (char*)malloc(sizeof(char) * 47);

	sprintf(output, "%04X %s %01X %01X %04X %01X %01X %01X %04X %04X\n", trace->PC, trace->instruction, trace->regFile_we,
			trace->Rd, trace->Rd_val, trace->NZP_we, trace->NZP_val, trace->data_we, trace->data_addr, trace->data_val);

	return output;
}







char* runRTIString(MachineState* machine, int instruction) {
	char* binaryInstruction =  binaryRepresentation(instruction);


	TraceStruct* newInstruction = newTraceStruct(machine->PC, binaryInstruction, 0, 0, 0, 0, 0, 0, 0, 0);


	machine -> priveledge = 0;

	machine -> PC = machine -> R7;
	char* output = newLineFromTrace(newInstruction);

	free(newInstruction);
	free(binaryInstruction);

	return output;

}

char* runTrapString(MachineState* machine, int instruction) {
	char* binaryInstruction =  binaryRepresentation(instruction);

	int currentPC = machine->PC;

	int immediate = grabSectionOfInstruction(instruction, 7, 0);

	int newPC = 0x8000 | immediate;

	machine->R7 = currentPC + 1;

	machine->priveledge = 1;

	int nzpval = nzpValueFrom(machine, 7);

	TraceStruct* newInstruction = newTraceStruct(currentPC, binaryInstruction, 1, 7, machine->R7, 1, nzpval, 0, 0, 0);


	char* output = newLineFromTrace(newInstruction);

	free(newInstruction);
	free(binaryInstruction);

	machine->PC = newPC;

	return output;


}



char* runHiConstString(MachineState* machine, int instruction) {
	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int RdVal = grabRegisterValue(machine, Rd);
	int unsignedOffSetImmediate = grabSectionOfInstruction(instruction, 7, 0);

	char* binaryInstruction = binaryRepresentation(instruction);

	RdVal = (RdVal & 0xFF) | (unsignedOffSetImmediate << 8);

	setRegisterValue(machine, Rd, RdVal);

	int nzpvalue = nzpValueFrom(machine, Rd);

	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 1, Rd, RdVal, 1, nzpvalue, 0, 0, 0);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);

	machine->PC++;
	machine->NZP = nzpvalue;

	return output;
}


char* runCONSTString(MachineState* machine, int instruction) {


	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int offSetImmediate = grabSectionOfInstruction(instruction, 8, 0);
	int offSet = signExtendInt(offSetImmediate, 9);

	setRegisterValue(machine, Rd, offSet);

	char* binaryInstruction = binaryRepresentation(instruction);

	int nzpvalue = nzpValueFrom(machine, Rd);

	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 1, Rd, offSet, 1, nzpvalue, 0, 0, 0);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);

	machine->PC++;
	
	return output;


}

char* runSTRString(MachineState* machine, int instruction, int LC4Memory[]) {
	int Rt = grabSectionOfInstruction(instruction, 11, 9);
	int Rtval = grabRegisterValue(machine, Rt);

	char* binaryInstruction = binaryRepresentation(instruction);

	int Rs = grabSectionOfInstruction(instruction, 8, 6);
	int Rsval = grabRegisterValue(machine, Rs);

	int offSetImmediate = grabSectionOfInstruction(instruction, 5, 0);
	int offSet = signExtendInt(offSetImmediate, 6);

	int memoryAddress = Rsval + offSet;

	if((memoryAddress <= 0x1fff) || (memoryAddress >= 0x8000 && memoryAddress <= 0x9fff)) {
		return NULL;
	} else if(memoryAddress >= 0x8000 && !(machine->priveledge)) {
		return NULL;
	}

	LC4Memory[memoryAddress] = Rtval;

	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 0, 0, 0, 0, 0, 1, memoryAddress, Rtval);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);

	machine->PC++;

	
	return output;

}

char* runLDRString(MachineState* machine, int instruction, int LC4Memory[]) {
	int Rd = grabSectionOfInstruction(instruction, 11, 9);

	int Rs = grabSectionOfInstruction(instruction, 8, 6);
	int Rsval = grabRegisterValue(machine, Rs);

	int offSetImmediate = grabSectionOfInstruction(instruction, 5, 0);
	int offSet = signExtendInt(offSetImmediate, 6);

	int dataAdrress = Rsval + offSet;

	if((dataAdrress <= 0x1fff) || (dataAdrress >= 0x8000 && dataAdrress <= 0x9fff)) {
		return NULL;
	} else if(dataAdrress >= 0x8000 && !(machine->priveledge)) {
		return NULL;
	}

	char* binaryInstruction = binaryRepresentation(instruction);

	setRegisterValue(machine, Rd, LC4Memory[dataAdrress]);

	int nzpvalue = nzpValueFrom(machine, Rd);


	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 1, Rd, LC4Memory[dataAdrress], 1, nzpvalue, 1, dataAdrress, LC4Memory[dataAdrress]);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);

	machine->PC++;
	
	return output;
}


char* runJumpString(MachineState* machine, int instruction) {
	int subOpCode = grabSectionOfInstruction(instruction, 11, 11);
	char* binaryInstruction = binaryRepresentation(instruction);
	int currentPC = machine->PC;
	switch(subOpCode) {
		int Rs;
		int Rsval;
		int offSetImmediate;
		int offSet;
		case 0:
			Rs = grabSectionOfInstruction(instruction, 8, 6);
			Rsval = grabRegisterValue(machine, Rs);

			machine->PC = Rsval;
			break;
		case 1:
			offSetImmediate = grabSectionOfInstruction(instruction, 10, 0);
			offSet = signExtendInt(offSetImmediate, 11);

			machine->PC++;

			machine->PC += offSet;
			break;
		default:
			break;
	}
	
	TraceStruct* trace = newTraceStruct(currentPC, binaryInstruction, 0, 0, 0, 0, 0, 0, 0, 0);
	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);
	
	return output;
}


char* runJString(MachineState* machine, int instruction) {
	int subOpCode = grabSectionOfInstruction(instruction, 11, 11);
	int currentPC = machine->PC;
	switch(subOpCode) {
		int Rs;
		int Rsval;
		int offSetImmediate;
		int offSet;
		case 0:
			Rs = grabSectionOfInstruction(instruction, 8, 6);
			Rsval = grabRegisterValue(machine, Rs);
			machine->PC = Rsval;
			break;
		case 1:
			offSetImmediate = grabSectionOfInstruction(instruction, 10, 0);
			offSet = signExtendInt(offSetImmediate, 11);
			machine->PC = ((machine -> PC) & 0x8000) | (offSet << 4);
			break;
		default:
			break;
	}
	char* binaryInstruction = binaryRepresentation(instruction);
	setRegisterValue(machine, 7, currentPC + 1);
	int nzpvalue = nzpValueFrom(machine, 7);
	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 1, 7, currentPC + 1, 1, nzpvalue, 0, 0, 0);
	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);
	
	return output;

}

char* runModString(MachineState* machine, int instruction) {
	int Rd = grabSectionOfInstruction(instruction, 11, 9);

	int Rs = grabSectionOfInstruction(instruction, 8, 6);
	int Rsval = grabRegisterValue(machine, Rs);

	int Rt = grabSectionOfInstruction(instruction, 2, 0);
	int Rtval = grabRegisterValue(machine, Rt);

	int valueToSet = Rsval % Rtval;

	char* binaryInstruction = binaryRepresentation(instruction);

	setRegisterValue(machine, Rd, valueToSet);

	int nzpvalue = nzpValueFrom(machine, Rd);


	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 1, Rd, valueToSet, 1, nzpvalue, 0, 0, 0);

	char *output = newLineFromTrace(trace);

	machine->PC++;

	free(trace);
	free(binaryInstruction);
	
	return output;
}


//Need to think about this one

char* runShiftString(MachineState* machine, int instruction) {
	char* output;

	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);
	int Rsval = grabRegisterValue(machine, Rs);

	char* binaryInstruction = binaryRepresentation(instruction);

	int unsignedOffset = grabSectionOfInstruction(instruction, 3, 0);

	int opCode = grabSectionOfInstruction(instruction, 5, 4);
	int valueToSet;
	int mask = power(2, 16) - 1;
	switch(opCode){
		
		
		case 0:

			valueToSet = Rsval << unsignedOffset;
			valueToSet = valueToSet & mask;

			valueToSet = signExtendInt(valueToSet, 16);
			
			setRegisterValue(machine, Rd, valueToSet);
			break;
		case 1:
			valueToSet = Rsval >> unsignedOffset;
			valueToSet = valueToSet & mask;

			valueToSet = signExtendInt(valueToSet, 16);

			setRegisterValue(machine, Rd, valueToSet);
			break;
		case 2:
			valueToSet = Rsval >> unsignedOffset;
			valueToSet = valueToSet & mask;

			valueToSet = signExtendInt(valueToSet, 16);

			setRegisterValue(machine, Rd, valueToSet);
			break;
		case 3:
			output = runModString(machine, instruction);
			return output;
		default:
			valueToSet = 0;
			break;
	}

	int nzpvalue = nzpValueFrom(machine, Rd);
	

	TraceStruct* trace = newTraceStruct(machine -> PC, binaryInstruction, 1, Rd, valueToSet, 1, nzpvalue, 0, 0, 0);

	output = newLineFromTrace(trace);

	machine->PC++;

	free(trace);
	free(binaryInstruction);

	return output;
}



char* runCompareString(MachineState* machine, int instruction) {
	int Rs = grabSectionOfInstruction(instruction, 11, 9);
	int usRsval = grabUnsignedRegisterValue(machine, Rs);
	int Rsval = grabRegisterValue(machine, Rs);

	int Rt = grabSectionOfInstruction(instruction, 2, 0);
	int usRtval = grabUnsignedRegisterValue(machine, Rt);
	int Rtval = grabRegisterValue(machine, Rt);

	int subOpCode = grabSectionOfInstruction(instruction, 8, 7);
	int nzpvalue;

	switch(subOpCode){
		int offSetImmediate;
		int offSet;
		int unsignedOffset;
		
		case 0:
			nzpvalue = nzpValueInt(machine, Rsval - Rtval);
			break;
		case 1:
			nzpvalue = nzpValueInt(machine, usRsval - usRtval);
			break;
		case 2:
			offSetImmediate = grabSectionOfInstruction(instruction, 6, 0);
			offSet = signExtendInt(offSetImmediate, 7);

			nzpvalue = nzpValueInt(machine, Rsval - offSet);
			break;
		case 3:
			unsignedOffset = grabSectionOfInstruction(instruction, 6, 0);

			nzpvalue = nzpValueInt(machine, usRsval - unsignedOffset);
			break;
		default:
			nzpvalue = machine->NZP;
			break;
	}

	char* binaryInstruction = binaryRepresentation(instruction);

	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 0, 0, 0, 1, nzpvalue, 0, 0, 0);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);

	machine->PC++;
	
	return output;
}


char* runOperatorString(MachineState* machine, int instruction) {
	int immediateAnd = grabSectionOfInstruction(instruction, 5, 5);

	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);

	int Rsval = grabRegisterValue(machine, Rs);

	TraceStruct* trace;

	char* binaryInstruction = binaryRepresentation(instruction);
	int nzpvalue;


	int valueToSet;

	if(immediateAnd) {
		int offSetImmediate = grabSectionOfInstruction(instruction, 4, 0);
		int offSet = signExtendInt(offSetImmediate, 5);

		valueToSet = Rsval & offSet;
	} else {
		int Rt = grabSectionOfInstruction(instruction, 2, 0);
		int Rtval = grabRegisterValue(machine, Rt);
		int subOpCode = grabSectionOfInstruction(instruction, 4, 3);

		switch(subOpCode) {
			case 0:
				valueToSet = Rtval & Rsval;
				break;
			case 1:
				valueToSet = ~Rsval;
				break;
			case 2:
				valueToSet = Rtval | Rsval;
				break;
			case 3:
				valueToSet = Rtval ^ Rsval;
				break;
			default:
				valueToSet = 0;
				break;
		}
	}

	setRegisterValue(machine, Rd, valueToSet);

	nzpvalue = nzpValueFrom(machine, Rd);

	trace = newTraceStruct(machine->PC, binaryInstruction, 1, Rd, valueToSet, 1, nzpvalue, 0, 0, 0);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);

	machine->PC++;
	
	return output;
}


char* runArithmeticString(MachineState* machine, int instruction) {
	int immediateAdd = grabSectionOfInstruction(instruction, 5, 5);
	int Rd = grabSectionOfInstruction(instruction, 11, 9);
	int Rs = grabSectionOfInstruction(instruction, 8, 6);
	int Rsval = grabRegisterValue(machine, Rs);

	

	int valueToSet;

	if(immediateAdd) {
		int offSetImmediate = grabSectionOfInstruction(instruction, 4, 0);
		int offSet = signExtendInt(offSetImmediate, 5);

		valueToSet = Rsval + offSet;
	} else {
		int Rt = grabSectionOfInstruction(instruction, 2, 0);
		int Rtval = grabRegisterValue(machine, Rt);
		int subOpCode = grabSectionOfInstruction(instruction, 4, 3);

		switch(subOpCode) {
			case 0:
				valueToSet = Rtval + Rsval;
				break;
			case 1:
				valueToSet = Rtval * Rsval;
				break;
			case 2:
				valueToSet = Rsval - Rtval;
				break;
			case 3:
				valueToSet = Rsval / Rtval;
				break;
			default:
				valueToSet = 0;
				break;
		}
	}

	char* binaryInstruction = binaryRepresentation(instruction);

	setRegisterValue(machine, Rd, valueToSet);

	int nzpvalue = nzpValueFrom(machine, Rd);

	TraceStruct* trace = newTraceStruct(machine->PC, binaryInstruction, 1, Rd, valueToSet, 1, nzpvalue, 0, 0, 0);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);

	machine->PC++;
	
	return output;
}

char* runBranchString(MachineState* machine, int instruction) {
	int offSetImmediate = grabSectionOfInstruction(instruction, 8, 0);
	int offSet = signExtendInt(offSetImmediate, 9);

	int branchDeterminer = grabSectionOfInstruction(instruction, 11, 9);

	int currentPC = machine->PC;
	machine->PC++;

	int nzpvalue = machine->NZP;
	
	switch(branchDeterminer) {
		case 0:
			break;
		case 1:
			if(nzpvalue == 1) {
				machine->PC += offSet;
			}
			break;
		case 2 : 
			if(nzpvalue == 2) {
				machine ->PC += offSet;
			}
			break;
		case 3 : 
			if(nzpvalue == 2 || nzpvalue == 1) {
				machine ->PC += offSet;
			}
			break;
		case 4 : 
			if(nzpvalue == 4) {
				machine ->PC += offSet;
			}
			break;
		case 5 : 
			if(nzpvalue == 4 || nzpvalue == 1) {
				machine->PC += offSet;
			}
			break;
		case 6 : 
			if(nzpvalue == 4 || nzpvalue == 2) {
				machine ->PC += offSet;
			}
			break;
		case 7 : 
			machine->PC += offSet;
			break;
		default:
			break;
	}

	char* binaryInstruction = binaryRepresentation(instruction);

	TraceStruct* trace;

	trace = newTraceStruct(currentPC, binaryInstruction, 0, 0, 0, 0, 0, 0, 0, 0);

	char* output = newLineFromTrace(trace);

	free(trace);
	free(binaryInstruction);


	return output;
}

char* runInstructionsString(MachineState* machine, int instruction, int LC4Memory[]) {
	

	int opCode = grabSectionOfInstruction(instruction, 15, 12);
	
	char* output = NULL; 
	switch (opCode) {
		case 0:
			output = runBranchString(machine, instruction);
			break;
		case 1:
			output = runArithmeticString(machine, instruction);
			break;
		case 10:
			output = runShiftString(machine, instruction);
			break;
		case 5:
			output = runOperatorString(machine, instruction);
			break;
		case 6:
			output = runLDRString(machine, instruction, LC4Memory);
			break;
		case 7:
			output = runSTRString(machine, instruction, LC4Memory);
			break;
		case 9:
			output = runCONSTString(machine, instruction);
			break;
		case 13:
			output = runHiConstString(machine, instruction);
			break;
		case 2:
			output = runCompareString(machine, instruction);
			break;
		case 4:
			output = runJString(machine, instruction);
			break;
		case 12:
			output = runJumpString(machine, instruction);
			break;
		case 15:
			output = runTrapString(machine, instruction);
			break;
		case 8:
			output = runRTIString(machine, instruction);
			break;
		default:
			sprintf(output, "INVALID INSTRUCTION");
	}
	
	return output;
}