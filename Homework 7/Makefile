parser: LC4.o parser.o Instructions.o loader.c
	clang -Wall -o parser loader.c parser.o LC4.o Instructions.o

parser.o: parser.c parser.h
	clang -Wall -c parser.c

lc4.o: LC4.c LC4.h
	clang -Wall -c LC4.c

instructions.o: Instructions.c Instructions.h
	clang -Wall -c Instructions.c

all: parser


