#include "montymain.h"

/**
 *_mod - computes the rest of the division of the second
 *top element of the stack by the top element of the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "mod");
		return;
	}

	if ((*stack)->next->n == 0)
	{
		lastTERROR();
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_number);
}
