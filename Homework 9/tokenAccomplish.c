#include "ctype.h"
#include "token.h"
#include "tokenAccomplish.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int diff = 0;
int coCounter = 0;


int counter = 0;
int l;
queue *queuer;

int createMLFor(FILE *file, token *ourToken) {


	char  *argument1 = malloc(1024 * sizeof(char));
	memset(argument1, 0, 1024);
	char *currBranchNumber = malloc(250 * sizeof(char));
	char *labRanch = malloc(250 * sizeof(char));
	char *ns = malloc(250 * sizeof(char));
	char stringOut[4100]  = {0};
	char *nts = malloc(1024 * sizeof(char));
	char *over = malloc(250 * sizeof(char));	
	int current;
	int numeroArgument;
	

	switch(ourToken->type) 
	{
		
		case LT: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tCMP R7 R2\n");

			strcat(stringOut,  "\tBRn ");

			sprintf(currBranchNumber, "%d", diff);
			diff = diff + 1;
			strcpy(labRanch, "lt_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);

			strcat(stringOut, "\n");

			strcat(stringOut, "\tCONST R4 #0\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");
			strcat(stringOut, "\tJMP END_");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");
			strcat(stringOut,  "\tCONST R4 #1\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");

			strcpy(over, "END_");
			strcat(over, "lt_");
			strcat(over, currBranchNumber);
			strcat(over, "\n");
			strcat(stringOut, over);

			break;

		case IF: 
			coCounter++;
			queuer = put(queuer, coCounter);
			sprintf(ns, "%d", queuer->count);
			strcat(stringOut, "IF_");
			strcat(stringOut ,ns);

			strcat(stringOut, "\n");
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tCMPI R7 #0\n");
			strcat(stringOut, "\tBRnz "  );
			strcat(stringOut, "ELSE_");
			strcat(stringOut ,ns);
			strcat(stringOut, "\n");

			break;

		case ELSE: 
			sprintf(ns, "%d", queuer->count);
			strcat(stringOut, "\tBRnzp ");
			strcat(stringOut, "END_IF_");
			strcat(stringOut ,ns);

			strcat(stringOut, "\n");
			strcat(stringOut, "ELSE_");
			strcat(stringOut ,ns);

			strcat(stringOut, "\n");
			break;

		case DEFUN: 
			l = 1;
			break;


		case RETURN: 
			strcat(stringOut, "\t;;;;epilogue;;;;\n");
			strcat(stringOut, "\tLDR R7 R6 #0\n\tSTR R7 R5 #2\n\tADD R6 R5 #0\n\tLDR R5 R6 #0\n\tLDR R7 R6 #1\n\tADD R6 R6 #3\n\tJMPR R7\n");
			break;

		case PLUS: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tADD R7 R7 R2\n");

			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");
			break;	

		case MINUS: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tSUB R7 R7 R2\n");

			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");		

			break;

		case MUL: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tMUL R7 R7 R2\n");	

			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");		
			break;	

		case DIV: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tDIV R7 R7 R2\n");

			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");		
			break;

		case MOD: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");

			strcat(stringOut,  "\tMOD R7 R7 R2\n");
			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");		
			break;

		case AND: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tAND R7 R7 R2\n");	

			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");				
			break;

		case OR: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tOR R7 R7 R2\n");	
			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");		
			break;


		case NOT: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tNOT R7 R7 R2\n");	

			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");		
			break;

		case ENDIF: 
			sprintf(ns, "%d", queuer->count);
			queuer = pull(queuer);
			strcat(stringOut, "END_IF_");

			strcat(stringOut ,ns);
			strcat(stringOut, "\n");
			break;

		case DROP: 
			strcat(stringOut, "\tADD R6 R6 #1\n");
			break;

		case DUP: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n");
			break;	

		case SWAP: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n\tSTR R2 R6 #-1\n\tADD R6 R6 #-1\n");
			break;	

		case ROT: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n\tLDR R3 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tSTR R2 R6 #-1\n\tADD R6 R6 #-1\n\tSTR R7 R6 #-1\n\tADD R6 R6 #-1\n\tSTR R3 R6 #-1\n\tADD R6 R6 #-1\n");
			break;

		case ARG: 
			numeroArgument = ourToken->arg_no + 2;
			sprintf(nts,"%d",numeroArgument);

			strcat(argument1, "\tLDR R3 R5 #");
			strcat(argument1, nts);
			strcat(stringOut, argument1);

			strcat(stringOut, "\n");
			strcat(stringOut, "\tSTR R3 R6 #-1\n\tADD R6 R6 #-1\n");
			break;
		case LITERAL: 
			
		 	current = ourToken->literal_value;
			char* stored_value = malloc(1024 * sizeof(char));
			char* B = malloc(1024 * sizeof(char));
			char* lB = malloc(1024 * sizeof(char));

			if(current < -256 || current > 256) {
				int l8b = current & 0xFF;
				int u8b = (current >> 8) & 0xFF;


				sprintf(B, "%d", u8b);
				sprintf(lB, "%d", l8b);

				strcat(stringOut,  "\tCONST R3 #");
				strcat(stringOut, lB);
				strcat(stringOut, "\n");
				strcat(stringOut, "\tHICONST R3 #");
				strcat(stringOut, B);
				strcat(stringOut, "\n");
				strcat(stringOut, "\tSTR R3 R6 #-1\n\tADD R6 R6 #-1\n");
			}
			else {
		
				
				sprintf(stored_value, "%d", current);
				strcat(stringOut,  "\tCONST R3 #");
				strcat(stringOut, stored_value);
				strcat(stringOut, "\n");
				strcat(stringOut, "\tSTR R3 R6 #-1\n\tADD R6 R6 #-1\n");

			}
			free(B);
			free(lB);
			free(stored_value);
			
			
			break;
		case BROKEN_TOKEN: 
			return 1;
			break;

		case LE: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tCMP R7 R2\n");
			strcat(stringOut, "\tBRnz ");

			sprintf(currBranchNumber, "%d", diff);
			diff = diff + 1;

			strcpy(labRanch, "le_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, "\tCONST R4 #0\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");
			strcat(stringOut,  "\tCONST R4 #1\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");

			strcpy(over, "END_");
			strcat(over, "le_");
			strcat(over, currBranchNumber);
			strcat(over, "\n");
			strcat(stringOut, over);
			break;

		case EQ: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tCMP R7 R2\n");
			strcat(stringOut, "\tBRz ");

			sprintf(currBranchNumber, "%d", diff);
			diff++;
			strcpy(labRanch, "eq_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, "\tCONST R4 #0\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");
			strcat(stringOut,  "\tCONST R4 #1\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");

			strcpy(over, "END_");
			strcat(over, "eq_");
			strcat(over, currBranchNumber);
			strcat(over, "\n");
			strcat(stringOut, over);
			break;

		case GE: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tCMP R7 R2\n");
			strcat(stringOut, "\tBRzp ");

			sprintf(currBranchNumber, "%d", diff);
			diff++;
			strcpy(labRanch, "ge_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, "\tCONST R4 #0\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");
			strcat(stringOut,  "\tCONST R4 #1\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");

			strcpy(over, "END_");
			strcat(over, "ge_");
			strcat(over, currBranchNumber);
			strcat(over, "\n");
			strcat(stringOut, over);

			break;

		case GT: 
			strcat(stringOut, "\tLDR R7 R6 #0\n\tADD R6 R6 #1\n\tLDR R2 R6 #0\n\tADD R6 R6 #1\n");
			strcat(stringOut, "\tCMP R7 R2\n");
			strcat(stringOut, "\tBRp ");

			sprintf(currBranchNumber, "%d", diff);
			diff++;
			strcpy(labRanch, "gt_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, "\tCONST R4 #0\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\n");
			strcat(stringOut,  "\tCONST R4 #1\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\n\tADD R6 R6 #-1\n");

			strcpy(over, "END_");
			strcat(over, "gt_");
			strcat(over, currBranchNumber);
			strcat(over, "\n");
			strcat(stringOut, over);

			break;
		default:
			printf("general error\n");
			return 1;
	}

	free(over);
	free(currBranchNumber);
	free(ns);
	free(nts);
	free(argument1);
	free(labRanch);
	fwrite(stringOut, sizeof(char), strlen(stringOut), file);
	return 0;

}