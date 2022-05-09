;; This is the data section
	.DATA
	.ADDR x4000		; Start the data at address 0x4000
	
global_primes_array

	;; Start of the code section
	;; R0 = n, R1 = output
	.CODE
	.ADDR 0x0000		; Start the code at address 0x0000

INIT	CONST R2, #0; 	Initialize num_primes to 0 (will add 1 at the first iteration)
		CONST R1, #2; 	Initialize First Number to test (inserted into array at first iteration)
		


FOUND_PRIME		ADD R2, R2, #1; Increment num_primes
		CMPU R2, R0; Checks to see if num_primes < n
		BRzp END; exits loop
		LEA R7, global_primes_array;	Stores address of global_primes array pointer in R7
		ADD R7, R7, R2; Moves pointer to end of array for newest item
		STR R1, R7, #0; Puts most recent tested value at end of array
		

NO_PRIME		ADD R1, R1, #1; Increment for next number to test
		ADD R3, R2, #0; Copy num_primes to R3 for decrementing (counter)
		LEA R7, global_primes_array;	Stores address of global_primes array pointer in R7
		


INNER			CMPI R3, #0; Checks to see if counter is at zero
		BRnz FOUND_PRIME;
		
		LDR R4, R7, #1; Loads value from array into R4
		MOD R4, R1, R4; Calculates MOD
		BRz NO_PRIME; Breaks inner loop to put item in global_array if (R1 % R4 == 0).

		ADD R7, R7, #1; Increments array pointer
		ADD R3, R3, #-1; Decreases counter
		BRnzp INNER;

END				NOP;