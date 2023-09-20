#include "monty.h"
/**
 * swap_func - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	int tmp;
	(void)line_number;

	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	else if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
/**
 * sub_func - function that subtracts the top element of the stack from the
 * second top element of the stack.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void sub_func(stack_t **stack,  unsigned int line_number)
{
if (stack == NULL)
	exit(EXIT_FAILURE);
if (!(*stack) || !((*stack)->next))
	{ fprintf(stderr, "L%d: can't sub, stack too short", line_number);
	free_all(stack);
	exit(EXIT_FAILURE); }
(*stack)->next->n -= (*stack)->n;
pop_func(stack, line_number);
}

