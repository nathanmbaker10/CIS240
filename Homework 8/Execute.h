typedef struct machine_state_struct {
	unsigned int priveledge;
	unsigned int NZP;
	unsigned int PC;
	unsigned int R0;
	unsigned int R1;
	unsigned int R2;
	unsigned int R3;
	unsigned int R4;
	unsigned int R5;
	unsigned int R6;
	unsigned int R7;
} MachineState;



typedef struct instruction_trace_struct {
	unsigned int PC;
	char* instruction;
	int regFile_we;
	int Rd;
	int Rd_val;
	int NZP_we;
	int NZP_val;
	int data_we;
	int data_addr;
	int data_val;
} TraceStruct; 


int grabRegisterValue(MachineState* machine, int reg);

int grabUnsignedRegisterValue(MachineState* machine, int reg);

void setRegisterValue(MachineState* machine, int reg, unsigned int val);

int nzpValueInt(MachineState* machine, int value);

int nzpValueFrom(MachineState* machine, int reg);

MachineState* newMachine();

char* binaryRepresentation(int instruction);

TraceStruct* newTraceStruct(int pc, char instruct[17], int regfilewe, int rd, int rd_val, int nzpwe, int nzpval, int datawe, int dataaddr, int dataval);

char* newLineFromTrace(TraceStruct* trace);

char* runRTIString(MachineState* machine, int instruction);

char* runTrapString(MachineState* machine, int instruction);

char* runHiConstString(MachineState* machine, int instruction);

char* runCONSTString(MachineState* machine, int instruction);

char* runSTRString(MachineState* machine, int instruction, int LC4Memory[]);

char* runLDRString(MachineState* machine, int instruction, int LC4Memory[]);

char* runJumpString(MachineState* machine, int instruction);

char* runJString(MachineState* machine, int instruction);

char* runModString(MachineState* machine, int instruction);

char* runShiftString(MachineState* machine, int instruction);

char* runCompareString(MachineState* machine, int instruction);

char* runOperatorString(MachineState* machine, int instruction);

char* runArithmeticString(MachineState* machine, int instruction);

char* runBranchString(MachineState* machine, int instruction);

char* runInstructionsString(MachineState* machine, int instruction, int LC4Memory[]);