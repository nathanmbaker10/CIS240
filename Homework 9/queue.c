#include <stdio.h>
#include <string.h>
#include "queue.h"
#include <stdlib.h>



queue *put (queue *top , int n)
{
	queue *new;
	new = (queue*) malloc(sizeof(*new));

  	new->count = n;
  	new->next = top;

  return new;
}

queue *pull(queue *top) 

{
	queue *n;

	if(top == NULL) {
		return top; 
	}

	n = top->next;



	top->next = NULL;


	free(top);

	return n;

}

queue* clear(queue *top) {
	while(top) {
		pull(top);
	}
	return top;
}
