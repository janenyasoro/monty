#include "montymain.h"

/**
 * interpret - reduces the code length on the driver
 * @monty_file: Monty file to be interpreted
 * Return: Exit status
 */
size_t interpret(FILE *monty_file)
{
	size_t exit_stat;
	stack_t *stack = NULL;
	
	if (stack_maker(&stack) == -1)
		return (EXIT_FAILURE);

	exit_stat = line_parser(monty_file, &stack);

	return (exit_stat);
}


/**
 * line_parser - Parses the line into precessable tokens
 * @monty_file: Name of the file being interepreted
 * @stack: Pointer to the stack
 * Return: 1 if failure else 0 on success
 */
size_t line_parser(FILE *monty_file, stack_t **stack)
{
	char *lineptr = NULL;
	size_t n = 0;
	size_t exit_stat = EXIT_SUCCESS;
	unsigned int line_number = 0, prevTLEN;
	short int empty;
	void (*opcodeFX)(stack_t**, unsigned int);

	while (getline(&lineptr, &n,monty_file) != -1)
	{
		line_number++;
		tok = _strtok(lineptr, DELIM);
		if (tok == NULL)
		{
			empty = empty_line_checker(lineptr, DELIM);
			if (empty)
				continue;
			free_plates(stack);
			return (EXIT_FAILURE);
		}

		else if (tok[0][0] == '#')
		{
			tok_free();
			continue;
		}

		opcodeFX =find_opcodeFX(tok[0]);
		if (opcodeFX == NULL)
		{
			free_plates(stack);
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, tok[0]);
			exit_stat = EXIT_FAILURE;
			tok_free();
			break;
		}

		prevTLEN = tok_len();
		opcodeFX(stack, line_number);
		if (tok_len() != prevTLEN)
		{
			exit_stat = EXIT_FAILURE;
			tok_free();
			break;
		}

		tok_free();

	}

	free_plates(stack);
	liner(&lineptr);

	return(exit_stat);

}

/**
 *free_plates - Frees stacks
 *@plates: Pointer to the stack
 *
 * Return: void
 */
void free_plates(stack_t **plates)
{
	stack_t *traverser = *plates;

	while(*plates != NULL)
	{
		traverser = (*plates)->next;
		free(*plates);
		*plates = traverser;
	}
}

/**
 *empty_line_checker - Checks if a line is empty
 *@lineptr: Pointer to the buffer containing the line
 *@delim: Defined delimiters
 *
 * Return: 1 if empty else 0
 */
short int empty_line_checker(char *lineptr, char *delim)
{
	int i = 0;
	int j = 0;

	while (lineptr[i])
	{
		while (delim[j])
		{
			if (lineptr[i] == delim[j])
				break;
			j++;
		}
		if (delim[j] == '\0')
			return (0);
		i++;
	}

	return (1);
}

/**
 *stack_maker - Creates a stack
 *@stack: Pointer to the stack
 *
 * Return: -1 if failed else 0
 */

int stack_maker(stack_t **stack)
{
	stack_t *plate;

	plate = malloc(sizeof(stack_t));
	if (plate == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	plate->n = 0;
	plate->prev = NULL;
	plate-> next = NULL;

	*stack = plate;

	return (0);
}
