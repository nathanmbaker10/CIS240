;; Fibbonacci Sequence
;; R0 = n; Output = R1 = F_n


	.CODE;
	.ADDR 0x0000; Starting Address for program

	CONST R2, #0; R2 will store F_{n - 2} (initialized to F_0 = 1)
	CONST R3, #1; R3 will store F_{n - 1} (initialized to F_1 = 1)
	CONST R1, #1; R1 will store F_n (initialized to F_2  = 1)
	ADD R0, R0, #-2; Subtract 2 from n because we have already initialized F_{n-1} and F{n-2}


LOOP	CMPI R0, #0;
	BRnz END;
	ADD R2, R3, #0 ; F_{n-2} = F_{n-1} 
	ADD R3, R1, #0 ; F_{n-1} = F_{n}
	ADD R1, R2, R3 ; F_{n} = F_{n-1} + F_{n-2}
	ADD R0, R0, #-1; n--
	BRnzp LOOP;

END NOP

