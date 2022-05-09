;;;;;;;;;;;;;;;;;;;;;;;;;;;;clear_screen;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
clear_screen
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	;; function body
	CONST R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #124
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #128
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
L1_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;draw_all_blocks;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
draw_all_blocks
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-4	;; allocate stack space for local variables
	;; function body
	CONST R7, #0
	STR R7, R5, #-2
L3_breakout
	CONST R7, #0
	STR R7, R5, #-1
L7_breakout
	LDR R7, R5, #-1
	SLL R7, R7, #4
	ADD R7, R7, #1
	STR R7, R5, #-3
	CONST R7, #10
	LDR R3, R5, #-2
	MUL R7, R7, R3
	ADD R7, R7, #1
	STR R7, R5, #-4
	LDR R7, R5, #-1
	LDR R3, R5, #-2
	SLL R3, R3, #3
	LEA R2, block_colors
	ADD R3, R3, R2
	ADD R7, R7, R3
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #8
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #14
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-4
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-3
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
L8_breakout
	LDR R7, R5, #-1
	ADD R7, R7, #1
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #8
	CMP R7, R3
	BRn L7_breakout
L4_breakout
	LDR R7, R5, #-2
	ADD R7, R7, #1
	STR R7, R5, #-2
	LDR R7, R5, #-2
	CONST R3, #5
	CMP R7, R3
	BRn L3_breakout
L2_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;clear_block;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
clear_block
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-2	;; allocate stack space for local variables
	;; function body
	LDR R7, R5, #4
	SLL R7, R7, #4
	STR R7, R5, #-1
	CONST R7, #10
	LDR R3, R5, #3
	MUL R7, R7, R3
	STR R7, R5, #-2
	CONST R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #10
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #16
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
	LDR R7, R5, #4
	LDR R3, R5, #3
	SLL R3, R3, #3
	LEA R2, block_colors
	ADD R3, R3, R2
	ADD R7, R7, R3
	CONST R3, #0
	STR R3, R7, #0
L11_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;redraw_ball;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
redraw_ball
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	;; function body
	CONST R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #3
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #4
	ADD R7, R7, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #3
	ADD R7, R7, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
	CONST R7, #255
	HICONST R7, #255
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #3
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #6
	ADD R7, R7, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #5
	ADD R7, R7, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
L12_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;redraw_paddle;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
redraw_paddle
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	;; function body
	CONST R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #3
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #11
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #120
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #3
	ADD R7, R7, #-5
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
	CONST R7, #255
	HICONST R7, #255
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #3
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #11
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #120
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #4
	ADD R7, R7, #-5
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
L13_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;reset_ball;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
reset_ball
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	;; function body
	LEA R7, ball_x
	CONST R3, #64
	STR R3, R7, #0
	LEA R3, ball_y
	CONST R2, #60
	STR R2, R3, #0
	CONST R3, #0
	LEA R2, ball_vel_x
	STR R3, R2, #0
	LEA R2, ball_vel_y
	STR R3, R2, #0
	LEA R3, ball_x_scaled
	LDR R7, R7, #0
	SLL R7, R7, #3
	STR R7, R3, #0
L14_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;reset_game;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
reset_game
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-1	;; allocate stack space for local variables
	;; function body
	LEA R7, lives_left
	CONST R3, #3
	STR R3, R7, #0
	CONST R7, #0
	LEA R3, blocks_smashed
	STR R7, R3, #0
	LEA R3, paddle_x
	CONST R2, #64
	STR R2, R3, #0
	LEA R3, paddle_vel_x
	STR R7, R3, #0
	JSR reset_ball
	ADD R6, R6, #0	;; free space for arguments
	CONST R7, #0
	STR R7, R5, #-1
L16_breakout
	LDR R7, R5, #-1
	LEA R3, block_colors
	ADD R7, R7, R3
	CONST R3, #112
	HICONST R3, #7
	STR R3, R7, #0
L17_breakout
	LDR R7, R5, #-1
	ADD R7, R7, #1
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #8
	CMP R7, R3
	BRn L16_breakout
	CONST R7, #0
	STR R7, R5, #-1
L20_breakout
	LDR R7, R5, #-1
	LEA R3, block_colors
	ADD R3, R3, #8
	ADD R7, R7, R3
	CONST R3, #0
	HICONST R3, #124
	STR R3, R7, #0
L21_breakout
	LDR R7, R5, #-1
	ADD R7, R7, #1
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #8
	CMP R7, R3
	BRn L20_breakout
	CONST R7, #0
	STR R7, R5, #-1
L24_breakout
	LDR R7, R5, #-1
	LEA R3, block_colors
	CONST R2, #16
	ADD R3, R3, R2
	ADD R7, R7, R3
	CONST R3, #0
	HICONST R3, #51
	STR R3, R7, #0
L25_breakout
	LDR R7, R5, #-1
	ADD R7, R7, #1
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #8
	CMP R7, R3
	BRn L24_breakout
	CONST R7, #0
	STR R7, R5, #-1
L28_breakout
	LDR R7, R5, #-1
	LEA R3, block_colors
	CONST R2, #24
	ADD R3, R3, R2
	ADD R7, R7, R3
	CONST R3, #51
	STR R3, R7, #0
L29_breakout
	LDR R7, R5, #-1
	ADD R7, R7, #1
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #8
	CMP R7, R3
	BRn L28_breakout
	CONST R7, #0
	STR R7, R5, #-1
L32_breakout
	LDR R7, R5, #-1
	LEA R3, block_colors
	CONST R2, #32
	ADD R3, R3, R2
	ADD R7, R7, R3
	CONST R3, #0
	HICONST R3, #246
	STR R3, R7, #0
L33_breakout
	LDR R7, R5, #-1
	ADD R7, R7, #1
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #8
	CMP R7, R3
	BRn L32_breakout
	JSR clear_screen
	ADD R6, R6, #0	;; free space for arguments
	JSR draw_all_blocks
	ADD R6, R6, #0	;; free space for arguments
	LEA R7, ball_y
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	LEA R3, ball_x
	LDR R3, R3, #0
	ADD R6, R6, #-1
	STR R3, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R3, R6, #0
	JSR redraw_ball
	ADD R6, R6, #4	;; free space for arguments
	LEA R7, paddle_x
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR redraw_paddle
	ADD R6, R6, #2	;; free space for arguments
L15_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;serve_ball;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
serve_ball
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	;; function body
	LEA R7, ball_vel_y
	LDR R7, R7, #0
	CONST R3, #0
	CMP R7, R3
	BRnp L37_breakout
	LEA R7, ball_x
	CONST R3, #64
	STR R3, R7, #0
	LEA R3, ball_y
	CONST R2, #60
	STR R2, R3, #0
	LEA R3, ball_vel_y
	CONST R2, #1
	STR R2, R3, #0
	LEA R3, ball_vel_x
	CONST R2, #8
	STR R2, R3, #0
	LEA R3, ball_x_scaled
	LDR R7, R7, #0
	SLL R7, R7, #3
	STR R7, R3, #0
L37_breakout
L36_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;update_paddle_state;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
update_paddle_state
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-1	;; allocate stack space for local variables
	;; function body
	LEA R7, paddle_x
	LDR R7, R7, #0
	STR R7, R5, #-1
	LDR R7, R5, #3
	CONST R3, #106
	CMP R7, R3
	BRnp L40_breakout
	LEA R7, paddle_vel_x
	LDR R3, R7, #0
	ADD R3, R3, #-1
	STR R3, R7, #0
	LDR R7, R7, #0
	CONST R3, #0
	CMP R7, R3
	BRn L42_breakout
	LEA R7, paddle_vel_x
	CONST R3, #-1
	STR R3, R7, #0
L42_breakout
	LEA R7, paddle_vel_x
	LDR R7, R7, #0
	CONST R3, #-4
	CMP R7, R3
	BRzp L44_breakout
	LEA R7, paddle_vel_x
	CONST R3, #-4
	STR R3, R7, #0
L44_breakout
L40_breakout
	LDR R7, R5, #3
	CONST R3, #107
	CMP R7, R3
	BRnp L46_breakout
	LEA R7, paddle_vel_x
	CONST R3, #0
	STR R3, R7, #0
L46_breakout
	LDR R7, R5, #3
	CONST R3, #108
	CMP R7, R3
	BRnp L48_breakout
	LEA R7, paddle_vel_x
	LDR R3, R7, #0
	ADD R3, R3, #1
	STR R3, R7, #0
	LDR R7, R7, #0
	CONST R3, #0
	CMP R7, R3
	BRp L50_breakout
	LEA R7, paddle_vel_x
	CONST R3, #1
	STR R3, R7, #0
L50_breakout
	LEA R7, paddle_vel_x
	LDR R7, R7, #0
	CONST R3, #4
	CMP R7, R3
	BRnz L52_breakout
	LEA R7, paddle_vel_x
	CONST R3, #4
	STR R3, R7, #0
L52_breakout
L48_breakout
	LEA R7, paddle_x
	LDR R3, R7, #0
	LEA R2, paddle_vel_x
	LDR R2, R2, #0
	ADD R3, R3, R2
	STR R3, R7, #0
	LDR R7, R7, #0
	CONST R3, #0
	CMP R7, R3
	BRzp L54_breakout
	LEA R7, paddle_x
	CONST R3, #0
	STR R3, R7, #0
L54_breakout
	LEA R7, paddle_x
	LDR R7, R7, #0
	CONST R3, #127
	CMP R7, R3
	BRnz L56_breakout
	LEA R7, paddle_x
	CONST R3, #127
	STR R3, R7, #0
L56_breakout
	LDR R7, R5, #-1
	LEA R3, paddle_x
	LDR R3, R3, #0
	CMP R7, R3
	BRnp L60_breakout
	LEA R7, ball_y
	LDR R7, R7, #0
	CONST R3, #119
	CMP R7, R3
	BRn L58_breakout
L60_breakout
	LEA R7, paddle_x
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR redraw_paddle
	ADD R6, R6, #2	;; free space for arguments
L58_breakout
L39_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;update_ball_position;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
update_ball_position
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-2	;; allocate stack space for local variables
	;; function body
	LEA R7, ball_x
	LDR R7, R7, #0
	STR R7, R5, #-1
	LEA R7, ball_y
	LDR R7, R7, #0
	STR R7, R5, #-2
	LEA R7, ball_y
	LDR R3, R7, #0
	LEA R2, ball_vel_y
	LDR R2, R2, #0
	ADD R3, R3, R2
	STR R3, R7, #0
	LEA R3, ball_x_scaled
	LDR R2, R3, #0
	LEA R1, ball_vel_x
	LDR R1, R1, #0
	ADD R2, R2, R1
	STR R2, R3, #0
	LEA R2, ball_x
	LDR R3, R3, #0
	CONST R1, #8
	DIV R3, R3, R1
	STR R3, R2, #0
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R2, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR redraw_ball
	ADD R6, R6, #4	;; free space for arguments
L61_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

		.DATA
L63_breakout 		.FILL #83
		.FILL #99
		.FILL #111
		.FILL #114
		.FILL #101
		.FILL #58
		.FILL #32
		.FILL #48
		.FILL #48
		.FILL #48
		.FILL #48
		.FILL #10
		.BLKW 1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;convert_int_to_string;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
convert_int_to_string
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-4	;; allocate stack space for local variables
	;; function body
	LDR R7, R5, #3
	STR R7, R5, #-2
	CONST R7, #0
	STR R7, R5, #-1
L64_breakout
	LDR R7, R5, #-2
	CONST R3, #10
	MOD R7, R7, R3
	STR R7, R5, #-3
	LDR R7, R5, #-2
	CONST R3, #10
	DIV R7, R7, R3
	STR R7, R5, #-2
	LDR R7, R5, #-3
	STR R7, R5, #-4
	CONST R3, #0
	CMP R7, R3
	BRz L70_breakout
	CONST R7, #1
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L71_breakout
	CONST R7, #2
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L72_breakout
	CONST R7, #3
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L73_breakout
	CONST R7, #4
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L74_breakout
	CONST R7, #5
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L75_breakout
	CONST R7, #6
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L76_breakout
	CONST R7, #7
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L77_breakout
	CONST R7, #8
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L78_breakout
	CONST R7, #9
	LDR R3, R5, #-4
	CMP R3, R7
	BRz L79_breakout
	JMP L69_breakout
L70_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #48
	STR R3, R7, #0
	JMP L69_breakout
L71_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #49
	STR R3, R7, #0
	JMP L69_breakout
L72_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #50
	STR R3, R7, #0
	JMP L69_breakout
L73_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #51
	STR R3, R7, #0
	JMP L69_breakout
L74_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #52
	STR R3, R7, #0
	JMP L69_breakout
L75_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #53
	STR R3, R7, #0
	JMP L69_breakout
L76_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #54
	STR R3, R7, #0
	JMP L69_breakout
L77_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #55
	STR R3, R7, #0
	JMP L69_breakout
L78_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #56
	STR R3, R7, #0
	JMP L69_breakout
L79_breakout
	CONST R7, #10
	LDR R3, R5, #-1
	SUB R7, R7, R3
	LEA R3, L63_breakout
	ADD R7, R7, R3
	CONST R3, #57
	STR R3, R7, #0
L69_breakout
L65_breakout
	LDR R7, R5, #-1
	ADD R7, R7, #1
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #4
	CMP R7, R3
	BRn L64_breakout
	LEA R7, L63_breakout
L62_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;handle_collision_with_walls;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
handle_collision_with_walls
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-1	;; allocate stack space for local variables
	;; function body
	LEA R7, ball_y
	LDR R7, R7, #0
	CONST R3, #123
	CMP R7, R3
	BRnp L81_breakout
	LEA R7, blocks_smashed
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR convert_int_to_string
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #1	;; free space for arguments
	STR R7, R5, #-1
	LEA R7, lives_left
	LDR R3, R7, #0
	ADD R3, R3, #-1
	STR R3, R7, #0
	LDR R7, R7, #0
	CONST R3, #0
	CMP R7, R3
	BRnp L83_breakout
	LEA R7, L85_breakout
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	LEA R7, blocks_smashed
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR convert_int_to_string
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #1	;; free space for arguments
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	JMP L82_breakout
L83_breakout
	CONST R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	CONST R7, #3
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	LEA R7, ball_y
	LDR R7, R7, #0
	ADD R7, R7, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	LEA R7, ball_x
	LDR R7, R7, #0
	ADD R7, R7, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_draw_rect
	ADD R6, R6, #5	;; free space for arguments
	JSR reset_ball
	ADD R6, R6, #0	;; free space for arguments
	LEA R7, blocks_smashed
	LDR R7, R7, #0
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR convert_int_to_string
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #1	;; free space for arguments
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	JMP L82_breakout
L81_breakout
	LEA R7, ball_y
	LDR R7, R7, #0
	CONST R3, #0
	CMP R7, R3
	BRp L86_breakout
	LEA R7, ball_vel_y
	LDR R3, R7, #0
	NOT R3,R3
	ADD R3,R3,#1
	STR R3, R7, #0
	JMP L87_breakout
L86_breakout
	LEA R7, ball_x
	LDR R7, R7, #0
	STR R7, R5, #-1
	CONST R3, #0
	CMP R7, R3
	BRnz L90_breakout
	CONST R7, #127
	LDR R3, R5, #-1
	CMP R3, R7
	BRn L88_breakout
L90_breakout
	LEA R7, ball_vel_x
	LDR R3, R7, #0
	NOT R3,R3
	ADD R3,R3,#1
	STR R3, R7, #0
L88_breakout
L87_breakout
L82_breakout
L80_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;handle_collision_with_paddle;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
handle_collision_with_paddle
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-1	;; allocate stack space for local variables
	;; function body
	LEA R7, ball_y
	LDR R7, R7, #0
	CONST R3, #120
	CMP R7, R3
	BRnp L92_breakout
	LEA R7, ball_x
	LDR R7, R7, #0
	LEA R3, paddle_x
	LDR R3, R3, #0
	SUB R7, R7, R3
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #0
	CMP R7, R3
	BRzp L94_breakout
	LDR R7, R5, #-1
	NOT R7,R7
	ADD R7,R7,#1
	STR R7, R5, #-1
L94_breakout
	LDR R7, R5, #-1
	SLL R7, R7, #1
	CONST R3, #11
	CMP R7, R3
	BRzp L96_breakout
	LEA R7, ball_vel_y
	CONST R3, #-1
	STR R3, R7, #0
	LEA R7, ball_vel_x
	LDR R3, R7, #0
	LEA R2, paddle_vel_x
	LDR R2, R2, #0
	ADD R3, R3, R2
	STR R3, R7, #0
	LDR R7, R7, #0
	CONST R3, #8
	CMP R7, R3
	BRnz L98_breakout
	LEA R7, ball_vel_x
	CONST R3, #8
	STR R3, R7, #0
L98_breakout
	LEA R7, ball_vel_x
	LDR R7, R7, #0
	CONST R3, #-8
	CMP R7, R3
	BRzp L100_breakout
	LEA R7, ball_vel_x
	CONST R3, #-8
	STR R3, R7, #0
L100_breakout
L96_breakout
L92_breakout
L91_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;handle_collision_with_blocks;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
handle_collision_with_blocks
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-3	;; allocate stack space for local variables
	;; function body
	LEA R7, ball_y
	LDR R7, R7, #0
	CONST R3, #10
	DIV R7, R7, R3
	STR R7, R5, #-1
	LEA R7, ball_x
	LDR R7, R7, #0
	CONST R3, #16
	DIV R7, R7, R3
	STR R7, R5, #-2
	LDR R7, R5, #-1
	CONST R3, #5
	CMPU R7, R3
	BRzp L103_breakout
	LDR R7, R5, #-2
	LDR R3, R5, #-1
	SLL R3, R3, #3
	LEA R2, block_colors
	ADD R3, R3, R2
	ADD R7, R7, R3
	LDR R7, R7, #0
	STR R7, R5, #-3
	LDR R7, R5, #-3
	CONST R3, #0
	CMP R7, R3
	BRz L105_breakout
	LEA R7, ball_y
	LDR R7, R7, #0
	CONST R3, #10
	LDR R2, R5, #-1
	ADD R1, R7, #0
	MUL R0, R3, R2
	CMP R1, R0
	BRz L109_breakout
	ADD R7, R7, #1
	ADD R2, R2, #1
	MUL R3, R3, R2
	CMP R7, R3
	BRnp L107_breakout
L109_breakout
	LEA R7, ball_vel_y
	CONST R3, #-1
	LDR R2, R7, #0
	MUL R3, R3, R2
	STR R3, R7, #0
	JMP L108_breakout
L107_breakout
	LEA R7, ball_vel_x
	CONST R3, #-1
	LDR R2, R7, #0
	MUL R3, R3, R2
	STR R3, R7, #0
L108_breakout
	LEA R7, blocks_smashed
	LDR R3, R7, #0
	ADD R3, R3, #1
	STR R3, R7, #0
	LDR R7, R5, #-2
	ADD R6, R6, #-1
	STR R7, R6, #0
	LDR R7, R5, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR clear_block
	ADD R6, R6, #2	;; free space for arguments
L105_breakout
L103_breakout
L102_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;main;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		.CODE
		.FALIGN
main
	;; prologue
	STR R7, R6, #-2	;; save return address
	STR R5, R6, #-3	;; save base pointer
	ADD R6, R6, #-3
	ADD R5, R6, #0
	ADD R6, R6, #-1	;; allocate stack space for local variables
	;; function body
	LEA R7, L111_breakout
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	LEA R7, L112_breakout
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	LEA R7, L113_breakout
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	LEA R7, L114_breakout
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	LEA R7, L115_breakout
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	LEA R7, L116_breakout
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_puts
	ADD R6, R6, #1	;; free space for arguments
	CONST R7, #50
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR lc4_set_timer
	ADD R6, R6, #1	;; free space for arguments
	JSR reset_game
	ADD R6, R6, #0	;; free space for arguments
	JMP L118_breakout
L117_breakout
	JSR lc4_check_timer
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #0	;; free space for arguments
	CONST R3, #0
	CMP R7, R3
	BRzp L120_breakout
	JSR lc4_getc
	LDR R7, R6, #-1	;; grab return value
	ADD R6, R6, #0	;; free space for arguments
	STR R7, R5, #-1
	LDR R7, R5, #-1
	CONST R3, #122
	CMP R7, R3
	BRnp L122_breakout
	JSR reset_game
	ADD R6, R6, #0	;; free space for arguments
L122_breakout
	LDR R7, R5, #-1
	CONST R3, #113
	CMP R7, R3
	BRnp L124_breakout
	LEA R7, lives_left
	LDR R7, R7, #0
	CONST R3, #0
	CMP R7, R3
	BRnz L124_breakout
	JSR serve_ball
	ADD R6, R6, #0	;; free space for arguments
L124_breakout
	JSR update_ball_position
	ADD R6, R6, #0	;; free space for arguments
	JSR handle_collision_with_walls
	ADD R6, R6, #0	;; free space for arguments
	JSR handle_collision_with_paddle
	ADD R6, R6, #0	;; free space for arguments
	JSR handle_collision_with_blocks
	ADD R6, R6, #0	;; free space for arguments
	LDR R7, R5, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	JSR update_paddle_state
	ADD R6, R6, #1	;; free space for arguments
L120_breakout
L118_breakout
	JMP L117_breakout
	CONST R7, #0
L110_breakout
	;; epilogue
	ADD R6, R5, #0	;; pop locals off stack
	ADD R6, R6, #3	;; free space for return address, base pointer, and return value
	STR R7, R6, #-1	;; store return value
	LDR R5, R6, #-3	;; restore base pointer
	LDR R7, R6, #-2	;; restore return address
	RET

		.DATA
blocks_smashed 		.BLKW 1
		.DATA
lives_left 		.BLKW 1
		.DATA
block_colors 		.BLKW 40
		.DATA
paddle_vel_x 		.BLKW 1
		.DATA
paddle_x 		.BLKW 1
		.DATA
ball_vel_y 		.BLKW 1
		.DATA
ball_vel_x 		.BLKW 1
		.DATA
ball_x_scaled 		.BLKW 1
		.DATA
ball_y 		.BLKW 1
		.DATA
ball_x 		.BLKW 1
		.DATA
L116_breakout 		.STRINGZ "Press z to reset game\n"
		.DATA
L115_breakout 		.STRINGZ "Press q to reset/serve ball\n"
		.DATA
L114_breakout 		.STRINGZ "Press l to move paddle right\n"
		.DATA
L113_breakout 		.STRINGZ "Press k to stop the paddle\n"
		.DATA
L112_breakout 		.STRINGZ "Press j to move paddle left\n"
		.DATA
L111_breakout 		.STRINGZ "!!! Welcome to Breakout !!!\n"
		.DATA
L85_breakout 		.STRINGZ "GAME OVER\n"
