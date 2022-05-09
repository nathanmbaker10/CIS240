		 .CODE
		 .FALIGN
fact
	;;;;prologue;;;;
	ADD R6 R6 #-3
	STR R7 R6 #1
	STR R5 R6 #0
	ADD R5 R6 #0
	;;;function body;;;;
	LDR R3 R6 #3
	STR R3 R6 #-1
	ADD R6 R6 #-1
	LDR R7 R6 #0
	STR R7 R6 #-1
	ADD R6 R6 #-1
	CONST R3 #1
	STR R3 R6 #-1
	ADD R6 R6 #-1
	LDR R7 R6 #0
	ADD R6 R6 #1
	LDR R2 R6 #0
	ADD R6 R6 #1
	CMP R7 R2
	BRzp ge_0
	CONST R4 #0
	STR R4 R6 #-1
	ADD R6 R6 #-1
	JMP END_ge_0
ge_0
	CONST R4 #1
	STR R4 R6 #-1
	ADD R6 R6 #-1
END_ge_0
IF_1
	LDR R7 R6 #0
	ADD R6 R6 #1
	CMPI R7 #0
	BRnz ELSE_1
	CONST R3 #1
	STR R3 R6 #-1
	ADD R6 R6 #-1
	BRnzp END_IF_1
ELSE_1
	LDR R7 R6 #0
	STR R7 R6 #-1
	ADD R6 R6 #-1
	CONST R3 #1
	STR R3 R6 #-1
	ADD R6 R6 #-1
	LDR R7 R6 #0
	ADD R6 R6 #1
	LDR R2 R6 #0
	ADD R6 R6 #1
	STR R7 R6 #-1
	ADD R6 R6 #-1
	STR R2 R6 #-1
	ADD R6 R6 #-1
	LDR R7 R6 #0
	ADD R6 R6 #1
	LDR R2 R6 #0
	ADD R6 R6 #1
	SUB R7 R7 R2
	STR R7 R6 #-1
	ADD R6 R6 #-1
	JSR fact
	ADD R6 R6 #-1
	LDR R7 R6 #0
	ADD R6 R6 #1
	LDR R2 R6 #0
	ADD R6 R6 #1
	STR R7 R6 #-1
	ADD R6 R6 #-1
	STR R2 R6 #-1
	ADD R6 R6 #-1
	ADD R6 R6 #1
	LDR R7 R6 #0
	ADD R6 R6 #1
	LDR R2 R6 #0
	ADD R6 R6 #1
	MUL R7 R7 R2
	STR R7 R6 #-1
	ADD R6 R6 #-1
END_IF_1
	;;;;epilogue;;;;
	LDR R7 R6 #0
	STR R7 R5 #2
	ADD R6 R5 #0
	LDR R5 R6 #0
	LDR R7 R6 #1
	ADD R6 R6 #3
	RET
		 .CODE
		 .FALIGN
main
	;;;;prologue;;;;
	ADD R6 R6 #-3
	STR R7 R6 #1
	STR R5 R6 #0
	ADD R5 R6 #0
	;;;function body;;;;
	CONST R3 #4
	STR R3 R6 #-1
	ADD R6 R6 #-1
	JSR fact
	ADD R6 R6 #-1
	JSR printnum
	ADD R6 R6 #-1
	JSR endl
	ADD R6 R6 #-1
	CONST R3 #5
	STR R3 R6 #-1
	ADD R6 R6 #-1
	JSR fact
	ADD R6 R6 #-1
	JSR printnum
	ADD R6 R6 #-1
	JSR endl
	ADD R6 R6 #-1
	CONST R3 #6
	STR R3 R6 #-1
	ADD R6 R6 #-1
	JSR fact
	ADD R6 R6 #-1
	JSR printnum
	ADD R6 R6 #-1
	JSR endl
	ADD R6 R6 #-1
	CONST R3 #7
	STR R3 R6 #-1
	ADD R6 R6 #-1
	JSR fact
	ADD R6 R6 #-1
	JSR printnum
	ADD R6 R6 #-1
	JSR endl
	ADD R6 R6 #-1
	;;;;epilogue;;;;
	LDR R7 R6 #0
	STR R7 R5 #2
	ADD R6 R5 #0
	LDR R5 R6 #0
	LDR R7 R6 #1
	ADD R6 R6 #3
	RET
