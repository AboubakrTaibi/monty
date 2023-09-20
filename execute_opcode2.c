#include "monty.h"

/**
 * add_func - function that adds the top two elements of the stack.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void add_func(stack_t **stack,  unsigned int line_number)
{

if (stack == NULL)
	exit(EXIT_FAILURE);
if (!(*stack) || !((*stack)->next))
	{ fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_all(stack);
	exit(EXIT_FAILURE); }
(*stack)->next->n += (*stack)->n;
pop_func(stack, line_number);
}
/**
 * div_func - function that divides the second top element of the stack by
 * the top element of the stack
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void div_func(stack_t **stack,  unsigned int line_number)
{

if (stack == NULL)
	exit(EXIT_FAILURE);
else if (!(*stack) || !((*stack)->next))
	{ fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	free_all(stack);
	exit(EXIT_FAILURE); }

else if (!(*stack)->n)
	{ fprintf(stderr, "L%d: division by zero\n", line_number);
	free_all(stack);
	exit(EXIT_FAILURE); }
else
{
(*stack)->next->n /= (*stack)->n;
pop_func(stack, line_number);
}
}

/**
 * mod_func - function that computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void mod_func(stack_t **stack,  unsigned int line_number)
{
	if (stack == NULL)
		exit(EXIT_FAILURE);
	else if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if (!(*stack)->n)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		pop_func(stack, line_number);
	}
}

