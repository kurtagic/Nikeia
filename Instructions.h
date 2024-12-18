#pragma once

/*
// NIKEIA INSTRUCTIONS
// PUSH - push to stack
// POP - pop from stack
// ADD - pop 2 numbers from stack, push the sum
// SUB - pop 2 numbers from stack, push the difference
// JUMP_EQL_0 - OPCODE LABEL: jump to label if top of stack is <= 0
// JUMP_GRT_0 - OPCODE LABEL: jump to label if top of stack is > 0
// PRINT OPCODE STRING_LITERAL: prints the string_literal to the terminal
// READ OPCODE: read number from I/O and push to stack
// HALT stop program
*/

#define PUSH "PUSH"
#define POP "POP"
#define ADD "ADD"
#define SUB "SUB"
#define GOTO "GOTO"
#define JUMP_EQL_0 "JUMP_EQL_0"
#define JUMP_GRT_0 "JUMP_GRT_0"
#define PRINT "PRINT"
#define PRINT_LINE "PRINT_LINE"
#define READ "READ"
#define HALT "HALT"
#define COMMENT "//"