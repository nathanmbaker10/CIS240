#include<stdio.h>
#include<stdlib.h>
#include "parser.h"


int readNextWord(FILE* file) {
	int firstByte = 0;
	int secondByte = 0;
	int combinedWord = 0;

	if(fread(&firstByte, 1, 1, file) == 0 || fread(&secondByte, 1, 1, file) == 0){
		return 2 ^ 32;
	}

	combinedWord = (firstByte << 8) + secondByte;
	return combinedWord;
}

int readNextByte(FILE* file) {
	int outputByte;

	if(fread(&outputByte, 1, 1, file) == 0){
		return 2 ^ 32;
	} else {
		return outputByte;
	}
}

Section findCurrentSection(FILE* file){
	int nextWord = readNextWord(file);
	switch(nextWord) {
		case 0xcade:
			return Code;
		case 0xdada:
			return DATA;
		case 0xc3b7:
			return Symbol;
		case 0xf17e:
			return FileName;
		case 0x715e:
			return LineNumber;
		case 2^32:
			
			return None;
		default:
			return findCurrentSection(file);
	}
}



void parseDATA_CodeSection(int memoryArray[], FILE* file, int startingAddress, int n) {

	int currentAddress;
	int newestWord;
	for (currentAddress = startingAddress; currentAddress < startingAddress + n; currentAddress++){
		newestWord = readNextWord(file);
		memoryArray[currentAddress] = newestWord;
		
	}
	parseFile(memoryArray, file);
}




void parseFile(int memoryArray[], FILE* file) {
	Section currentSection = findCurrentSection(file);
	int startingAddress, n, i;
	switch(currentSection) {
		case Code:
			
			startingAddress = readNextWord(file);
			n = readNextWord(file);

			parseDATA_CodeSection(memoryArray, file, startingAddress, n);
			break;
		case DATA:
			
			startingAddress = readNextWord(file);
			n = readNextWord(file);

			parseDATA_CodeSection(memoryArray, file, startingAddress, n);
		case Symbol:
			
			startingAddress = readNextWord(file);
			
			n = readNextWord(file);
			for (i = 0; i < n; i++){
				readNextByte(file);
			}
			parseFile(memoryArray, file);
			break;
		case FileName:
			
			startingAddress = readNextWord(file);
			n = readNextWord(file);
			for (i = 0; i < n; i++){
				readNextWord(file);
			}
			parseFile(memoryArray, file);
			break;
		case LineNumber:
			startingAddress = readNextWord(file);
			readNextWord(file);
			readNextWord(file);
			parseFile(memoryArray, file);
			break;
		case None:
			// fclose(file);
			break;
		default:
			printf("ERROR: No Section Found");
	}
}




