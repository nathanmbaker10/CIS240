#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200


int main() {

	StackHead* STACK = newStackHead();
	char userInput[MAX_LINE_LENGTH];
	char name[MAX_LINE_LENGTH];

	int value, i;
	while(1) {
		char userInput[MAX_LINE_LENGTH];
		fgets(userInput, MAX_LINE_LENGTH, stdin);
		
		for (i = 0; userInput[i]; i++) {
			userInput[i] = tolower(userInput[i]);
		}

		if(sscanf(userInput, "%s%s", name, name) == 1) {
			//char dup[] = "dup";
			if (strcmp(name, "dup") == 0) {
				duplicateHead(STACK);
			}

			else if (strcmp(name, "swap") == 0) {
				swap(STACK);
			}

			else if (strcmp(name, "drop") == 0) {
				if(!(STACK->head)) {
					printf("STACK ERROR\n");
				} else {
					drop(STACK);	
				}
				
			}

			else if(strcmp(name, "clear") == 0) {
				clear(STACK);
			}

			else if(strcmp(name, "+") == 0) {
				addFracs(STACK);
			}

			else if(strcmp(name, "-") == 0) {
				subtractFracs(STACK);
			}
			else if(strcmp(name, "/") == 0) {
				if(divideFracs(STACK) == 0) {
					clear(STACK);
					break;
				};
			}
			else if(strcmp(name, "*") == 0) {
				multiplyFracs(STACK);
			}

			else if(sscanf(userInput, "%d", &value)) {
				addIntegersTo(STACK, value, 1);
			}

			else if(strcmp(name, "quit") == 0) {
				clear(STACK);
				break;
			} else {
				printf("INVALID COMMAND\n");
				continue;
			}
			if(STACK->head) {
				StackElement * head = STACK -> head;
				Fraction topValue = head->value;



				printf("%d/%d\n", topValue.numerator, topValue.denominator);
			}
		} else {
			printf("INVALID COMMAND\n");
		}


	}
}