jc: token.o jparser.c queue.o
	clang -o jc token.o queue.o jparser.c 

token: token.h token.c
	clang -c token.h token.c

queue: queue.h queue.c
	clang -c queue.h queue.c
	
clean: 
	rm jc *.o