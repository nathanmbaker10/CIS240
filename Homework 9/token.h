#include <stdio.h>





#define MAX_TOKEN_LENGTH 250

typedef struct {
  enum { DEFUN, IDENT, RETURN, 
         PLUS, MINUS, MUL, DIV, MOD, 
         AND, OR, NOT, 
         LT, LE, EQ, GE, GT,
         IF, ELSE, ENDIF, 
         DROP, DUP, SWAP, ROT, ARG,
         LITERAL,
         BROKEN_TOKEN } type;
  int literal_value;    // this field used to store the value of literal tokens
  int arg_no;           // this field used to store the index of argument literals argN
  char str[MAX_TOKEN_LENGTH];
} token;


int functionMain(char* tokenString, token *tokenReal);

int createMLFor(FILE *file, token *ourToken);

void printToken(token* toPrint);


extern int line_number;
