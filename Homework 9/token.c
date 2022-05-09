#include "ctype.h"
#include "token.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int diff = 0;
int coCounter = 0;

int l = 1;

int counter = 0;

queue *queuer;
int elseCount = 0;


int functionMain(char* tokenString, token *tokenReal) {
	
	

	int stringLen = strlen(tokenString);
	
	
	if(stringLen > 3  && stringLen < 6){
	

		if(tokenString[0] == 'a' && tokenString[1] == 'r' && tokenString[2] == 'g') {

			tokenReal->type = ARG;

			if(isdigit(tokenString[3]) && stringLen == 4) {
				tokenReal->arg_no = (int)(tokenString[3] - 48);
				return -1;
			}

			else if(isdigit(tokenString[4]) && stringLen == 5 && isdigit(tokenString[3]) ) {

				char na[2] = {tokenString[3], tokenString[4]};
				int an = atoi(na);

				if(an > 20) {
					return 1;
				}	

				tokenReal->arg_no = an;
				return -1;
			}
		}

	}

	
	if(strcmp(tokenString, "return") == 0) {
		tokenReal->type = RETURN;
		return -1;	
	}
	else if(strcmp(tokenString, "defun") == 0) {
		tokenReal->type = DEFUN;
		return -1;
	}

	else if(strcmp(tokenString, "+") == 0) {
		tokenReal->type = PLUS;
		return -1;
	}
	else if(strcmp(tokenString, "else") == 0) {
		tokenReal->type = ELSE;
		return -1;
	}
	else if(strcmp(tokenString, "drop") == 0) {
		tokenReal->type = DROP;
		return -1;
	}
	else if(strcmp(tokenString, "endif") == 0) {
		tokenReal->type = ENDIF;
		return -1;
	}
	
	else if(strcmp(tokenString, "dup") == 0) {
		tokenReal->type = DUP;
		return -1;
	}
	else if(strcmp(tokenString, "swap") == 0) {
		tokenReal->type = SWAP;
		return -1;
	}

	else if(strcmp(tokenString, "rot") == 0) {
		tokenReal->type = ROT;
		return -1;
	} else if(strcmp(tokenString, "or") == 0) {
		tokenReal->type = OR;
		return -1;
	}
	else if(strcmp(tokenString, "%") == 0) {
		tokenReal->type = MOD;
		return -1;
	}
	else if(strcmp(tokenString, "not") == 0) {
		tokenReal->type = NOT;
		return -1;
	}
	else if(strcmp(tokenString, "-") == 0) {
		tokenReal->type = MINUS;
		return -1;
	}

	else if(strcmp(tokenString, "/") == 0) {
		tokenReal->type = DIV;
		return -1;
	}

	else if(strcmp(tokenString, "*") == 0) {
		tokenReal->type = MUL;
		return -1;
	}
	
	else if(strcmp(tokenString, "and") == 0) {
		tokenReal->type = AND;
		return -1;
	}
	
	else if(strcmp(tokenString, "lt") == 0) {
		tokenReal->type = LT;
		return -1;
	}
	else if(strcmp(tokenString, "le") == 0) {
		tokenReal->type = LE;
		return -1;
	}
	else if(strcmp(tokenString, "eq") == 0) {
		tokenReal->type = EQ;
		return -1;
	}
	else if(strcmp(tokenString, "ge") == 0) {
		tokenReal->type = GE;
		return -1;
	}
	else if(strcmp(tokenString, "gt") == 0) {
		tokenReal->type = GT;
		return -1;
	}
	else if(strcmp(tokenString, "if") == 0) {
		
		tokenReal->type = IF;
		return -1;
	}
	int x;
	

	

	if(tokenString[1] == 'x' && tokenString[0] == '0'){

		tokenReal->type = LITERAL;

		tokenReal->literal_value = (int)strtol(tokenString, NULL, 16);
		

		return -1;
	} else if(isdigit(tokenString[0]) || tokenString[0] == '-') 
	{
		
		for(x = 1; x < stringLen; x++) {
			if(!isdigit(tokenString[x])) {
				return 1;

			}
		}

		
		tokenReal->literal_value = atoi(tokenString);
		tokenReal->type = LITERAL;

		return -1;
		
	
	} 

	else 
	{
		
		if(!isalpha(tokenString[0])) {
			
			tokenReal->type = BROKEN_TOKEN;
			return -1;
		} else {
			tokenReal->type = IDENT;

		}

		for(x = 1; x < stringLen; x++) {
			if(!(isalnum(tokenString[x]) || tokenString[x] == '_')) {
				
				return 1;
			}
		}
		
		tokenReal->type = 1;
		strcpy(tokenReal->str, tokenString);


		return -1;
	}

}

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
		case IDENT: 
			
			
			if(l == 1) {
				
					

				strcat(stringOut, "\t\t .CODE\r\n");
				strcat(stringOut, "\t\t .FALIGN\r\n");
				strcat(stringOut, ourToken->str);
				
				strcat(stringOut, "\r\n");
				strcat(stringOut, "\t;;;;prologue;;;;\r\n");
				strcat(stringOut, "\tADD R6 R6 #-3\r\n\tSTR R7 R6 #1\r\n\tSTR R5 R6 #0\r\n\tADD R5 R6 #0\r\n");

				
				strcat(stringOut, "\t;;;function body;;;;\r\n");


				
			} else {
				

				strcat(stringOut, "\tJSR ");			
				strcat(stringOut, ourToken->str);

				strcat(stringOut, "\r\n");
				strcat(stringOut, "\tADD R6 R6 #-1\r\n");
			}
			l = 0;
			break;
		
		case LT: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tCMP R7 R2\r\n");

			strcat(stringOut,  "\tBRn ");

			sprintf(currBranchNumber, "%d", diff);
			diff = diff + 1;
			strcpy(labRanch, "lt_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);

			strcat(stringOut, "\r\n");

			strcat(stringOut, "\tCONST R4 #0\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			strcat(stringOut, "\tJMP END_");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");
			strcat(stringOut,  "\tCONST R4 #1\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");

			strcpy(over, "END_");
			strcat(over, "lt_");
			strcat(over, currBranchNumber);
			strcat(over, "\r\n");
			strcat(stringOut, over);

			break;

		case IF: 
			
			coCounter++;
			queuer = put(queuer, coCounter);
			sprintf(ns, "%d", queuer->count);
			strcat(stringOut, "IF_");
			strcat(stringOut,ns);

			strcat(stringOut, "\r\n");
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tCMPI R7 #0\r\n");
			strcat(stringOut, "\tBRnz "  );
			strcat(stringOut, "ELSE_");
			strcat(stringOut,ns);
			strcat(stringOut, "\r\n");

			break;

		case ELSE:
			elseCount++;
			sprintf(ns, "%d", queuer->count);
			strcat(stringOut, "\tBRnzp ");
			strcat(stringOut, "END_IF_");
			strcat(stringOut,ns);

			strcat(stringOut, "\r\n");
			strcat(stringOut, "ELSE_");
			strcat(stringOut,ns);

			strcat(stringOut, "\r\n");
			break;

		case DEFUN: 
			l = 1;
			break;


		case RETURN: 
			strcat(stringOut, "\t;;;;epilogue;;;;\r\n");
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tSTR R7 R5 #2\r\n\tADD R6 R5 #0\r\n\tLDR R5 R6 #0\r\n\tLDR R7 R6 #1\r\n\tADD R6 R6 #3\r\n\tRET\r\n");
			break;

		case PLUS: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tADD R7 R7 R2\r\n");

			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			break;	

		case MINUS: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tSUB R7 R7 R2\r\n");

			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");		

			break;

		case MUL: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tMUL R7 R7 R2\r\n");	

			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");		
			break;	

		case DIV: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tDIV R7 R7 R2\r\n");

			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");		
			break;

		case MOD: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");

			strcat(stringOut,  "\tMOD R7 R7 R2\r\n");
			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");		
			break;

		case AND: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tAND R7 R7 R2\r\n");	

			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");				
			break;

		case OR: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tOR R7 R7 R2\r\n");	
			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");		
			break;


		case NOT: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tNOT R7 R7 R2\r\n");	

			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");		
			break;

		case ENDIF: 
			sprintf(ns, "%d", queuer->count);
			if(elseCount < queuer-> count) {
				strcat(stringOut, "ELSE_");
				strcat(stringOut, ns);
				strcat(stringOut, "\r\n");
			}
			queuer = pull(queuer);
			strcat(stringOut, "END_IF_");

			strcat(stringOut,ns);
			strcat(stringOut, "\r\n");
			break;

		case DROP: 
			strcat(stringOut, "\tADD R6 R6 #1\r\n");
			break;

		case DUP: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			break;	

		case SWAP: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n\tSTR R2 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			break;	

		case ROT: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R3 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tSTR R2 R6 #-1\r\n\tADD R6 R6 #-1\r\n\tSTR R7 R6 #-1\r\n\tADD R6 R6 #-1\r\n\tSTR R3 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			break;

		case ARG: 
			numeroArgument = ourToken->arg_no + 2;
			sprintf(nts,"%d",numeroArgument);

			strcat(argument1, "\tLDR R3 R6 #");
			strcat(argument1, nts);
			strcat(stringOut, argument1);

			strcat(stringOut, "\r\n");
			strcat(stringOut, "\tSTR R3 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
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
				strcat(stringOut, "\r\n");
				strcat(stringOut, "\tHICONST R3 #");
				strcat(stringOut, B);
				strcat(stringOut, "\r\n");
				strcat(stringOut, "\tSTR R3 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			}
			else {
		
				
				sprintf(stored_value, "%d", current);
				strcat(stringOut,  "\tCONST R3 #");
				strcat(stringOut, stored_value);
				strcat(stringOut, "\r\n");
				strcat(stringOut, "\tSTR R3 R6 #-1\r\n\tADD R6 R6 #-1\r\n");

			}
			free(B);
			free(lB);
			free(stored_value);
			
			
			break;
		case BROKEN_TOKEN: 
			
			break;

		case LE: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tCMP R7 R2\r\n");
			strcat(stringOut, "\tBRnz ");

			sprintf(currBranchNumber, "%d", diff);
			diff = diff + 1;

			strcpy(labRanch, "le_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, "\tCONST R4 #0\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");
			strcat(stringOut,  "\tCONST R4 #1\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");

			strcpy(over, "END_");
			strcat(over, "le_");
			strcat(over, currBranchNumber);
			strcat(over, "\r\n");
			strcat(stringOut, over);
			break;

		case EQ: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tCMP R7 R2\r\n");
			strcat(stringOut, "\tBRz ");

			sprintf(currBranchNumber, "%d", diff);
			diff++;
			strcpy(labRanch, "eq_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, "\tCONST R4 #0\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");
			strcat(stringOut,  "\tCONST R4 #1\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");

			strcpy(over, "END_");
			strcat(over, "eq_");
			strcat(over, currBranchNumber);
			strcat(over, "\r\n");
			strcat(stringOut, over);
			break;

		case GE: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tCMP R7 R2\r\n");
			strcat(stringOut, "\tBRzp ");

			sprintf(currBranchNumber, "%d", diff);
			diff++;
			strcpy(labRanch, "ge_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, "\tCONST R4 #0\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");
			strcat(stringOut,  "\tCONST R4 #1\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");

			strcpy(over, "END_");
			strcat(over, "ge_");
			strcat(over, currBranchNumber);
			strcat(over, "\r\n");
			strcat(stringOut, over);

			break;

		case GT: 
			strcat(stringOut, "\tLDR R7 R6 #0\r\n\tADD R6 R6 #1\r\n\tLDR R2 R6 #0\r\n\tADD R6 R6 #1\r\n");
			strcat(stringOut, "\tCMP R7 R2\r\n");
			strcat(stringOut, "\tBRp ");

			sprintf(currBranchNumber, "%d", diff);
			diff++;
			strcpy(labRanch, "gt_");
			strcat(labRanch, currBranchNumber);

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, "\tCONST R4 #0\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");
			strcat(stringOut, "\tJMP END_");
			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");

			strcat(stringOut, labRanch);
			strcat(stringOut, "\r\n");
			strcat(stringOut,  "\tCONST R4 #1\r\n");
			strcat(stringOut, "\tSTR R4 R6 #-1\r\n\tADD R6 R6 #-1\r\n");

			strcpy(over, "END_");
			strcat(over, "gt_");
			strcat(over, currBranchNumber);
			strcat(over, "\r\n");
			strcat(stringOut, over);

			break;
		default:
			return 0;
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


void printToken(token* toPrint) {
	printf("Token Type: %d\r\n", (int)toPrint->type);
}