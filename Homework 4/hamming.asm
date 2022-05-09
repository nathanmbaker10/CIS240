;; Hamming Distance Script
;; A = R0, B = R1
;; Output (Hamming distance between A and B) stored in R2

	.CODE		 ;
	.ADDR   0x0000	;


	CONST R2, #0; initialize Hamming distance to 0

	XOR R3, R0, R1; XOR of A and B stored in R3

LOOP	CMPIU R3, #0; Sees if R3 is 0
	BRz END;
	AND R4, R3, #1; Checks to see if LSB is 1
	ADD R2, R2, R4; Adds result of AND to hamming distance
	SRL R3, R3, #1; Shifts bits right for next iteration
	BRnzp LOOP;

END 	NOP;


