parser: LC4.o parser.o Instructions.o loader.c
	clang -Wall -o parser loader.c parser.o LC4.o Instructions.o

trace: LC4.o Instructions.o parser.o Execute.o loader.c
	clang -Wall -o trace loader.c parser.o LC4.o Instructions.o Execute.o

parser.o: parser.c parser.h
	clang -Wall -c parser.c

lc4.o: LC4.c LC4.h
	clang -Wall -c LC4.c

instructions.o: Instructions.c Instructions.h
	clang -Wall -c Instructions.c

Execute.o: Execute.c Execute.h
	clang -Wall -c Execute.c

all: trace

clean:
	rm trace *.o
