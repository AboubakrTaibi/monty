#include "monty.h"

/**
 * swap_func - function that adds the top two elements of the stack.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void swap_func(stack_t **stack,  unsigned int line_number)
{

if (stack == NULL)
	exit(EXIT_FAILURE);
if (!(*stack) || !((*stack)->next))
	{ fprintf(stderr, "L%d: can't add, stack too short", line_number);
	free_all(stack);
	exit(EXIT_FAILURE); }
(*stack)->next->n += (*stack)->n;
pop_func(stack, line_number);
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

