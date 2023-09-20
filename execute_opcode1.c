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
 * sub_func - subtracts the top element from
 * the second top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		exit(EXIT_FAILURE);
	else if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n -= (*stack)->n;
		pop_func(stack, line_number);
	}
}

/**
 * mul_func - multiplies the second top element
 * of the stack with the top element
 * @stack: pointer to the top of the stack
 * @line_number: line number of the instruction
 */
void mul_func(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		exit(EXIT_FAILURE);
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n *= (*stack)->n;
		pop_func(stack, line_number);
	}
}
