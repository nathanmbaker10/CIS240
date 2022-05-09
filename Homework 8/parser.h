//Creates an enum for determining which section of the 
typedef enum section_enum {
	None,
	Code,
	DATA,
	Symbol,
	LineNumber,
	FileName

} Section;


//Returns two byte word in big-endian format (MSB is before LSB)
int readNextWord(FILE* file);

//Returns one byte integer
int readNextByte(FILE* file);

//Determines which section of binary file we are in
Section findCurrentSection(FILE* file);

//Parses section of input file at starting address with knowledge that we are in DATA or Code section with n words
void parseData_CodeSection(int memoryArray[], FILE* file, int startingAddress, int n);

//Parses file by calling other functions recursively until the end of the file
void parseFile(int memoryArray[], FILE* file);

