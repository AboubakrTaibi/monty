#include "monty.h"
/**
 * free_stack - function that frees a stack.
 * @stack: pointer to linked lists
 */
void free_stack(stack_t *stack)
{
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			free(stack->prev);
		}
		free(stack);
	}
}
