#include "montymain.h"
/**
 *_pint - prints the value at the top of the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 *_swap - swaps the top two elements of the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "swap");
		return;
	}

	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->prev = temp;

	if (temp->next)
		temp->next->prev = (*stack)->next;

	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}

/**
 *_pop - removes the top element of the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);

	if (next)
		next->prev = *stack;

	(*stack)->next = next;
}

/**
 *_pall -  prints all the values on the stack, from the top of the stack.
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 *_push - Pushes an element to the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;
	int i = 0;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		lastTERROR();
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	if (tok[1] == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new);
		return;
	}

	for (i = 0; tok[1][i]; i++)
	{
		if (tok[1][i] == '-' && i == 0)
			continue;

		if (tok[1][i] < '0' || tok[1][i] > '9')
		{
			lastTERROR();
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(new);
			return;
		}
	}

	new->n = atoi(tok[1]);
	temp = (*stack)->next;
	new->prev = *stack;
	new->next = temp;

	if (temp != NULL)
		temp->prev = new;

	(*stack)->next = new;
}
