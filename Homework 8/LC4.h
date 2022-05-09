int power(int base, int exp);

int grabSectionOfInstruction(int instruction, int msb, int lsb);

int signExtendInt(int n, int numBits);

void writeDATALine(FILE* outputFile, int memoryArray[], int address);

void writeCodeLine(FILE* outputFile, int memoryArray[], int address);

void writeToOutputFile(char* outputFile, int memoryArray[]);

void beginTrace(char* outputFileString, int memoryArray[]);