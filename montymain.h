#ifndef __MONTYC__
#define __MONTYC__

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DELIM " \n\t\a\b"

extern char **tok;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*1_montyfunc.c*/
size_t interpret(FILE *monty_file);
int stack_maker(stack_t **stack);
size_t line_parser(FILE *monty_file, stack_t **stack);
short int empty_line_checker(char *lineptr, char *delim);
void free_plates(stack_t **plates);

/*2_montyfunc.c*/
void tok_free(void);
void (*find_opcodeFX(char *opcode))(stack_t**, unsigned int);
unsigned int tok_len(void);
void liner(char **lineptr);
char **_strtok(char *str, char *delims);

/*op1codes.c*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/*op2codes.c*/
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);

/*3_montyfunc.c*/
int _isDelim(char ch, char *delims);
int get_wl(char *str, char *delims);
int get_wc(char *str, char *delims);
char *get_nw(char *str, char *delims);
void lastTERROR(void);

/*4_montyfunc.c*/
void _mod(stack_t **stack, unsigned int line_number);

#endif /*__MONTYC__*/
