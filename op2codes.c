#include "montymain.h"
/**
 *_sub - subtracts the top element of the stack from the second
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "sub");
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 *_add - adds the top two elements of the stack
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "add");
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 *_nop - Doesn't do anything
 *@stack: Pointer to the stack
 *@line_number: Current line number of file
 *
 * Return: Void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * _div - Divides the second value
 * @stack: A pointer to the top mode node
 * @line_number: The current working line number
 *
 * Description: The result is stored in the second value node
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "div");
		return;
	}

	if ((*stack)->next->n == 0)
	{
		lastTERROR();
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mul - Multiplies the second value
 * @stack: A pointer to the top mode node
 * @line_number: The current working line number
 * Description: The result is stored in the second value node
 *
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		lastTERROR();
		fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, "mul");
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_number);
}
