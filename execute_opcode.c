#include "monty.h"
/**
 * execute_opcode - function that find and call the appropriate function
 * @stack: pointer to stack list
 * @line_number: number of line in file
 * @opcode: pointer to a instruction
 */
void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	print_error(line_number, ": unknown instruction ", opcode);
}
/**
 * push_func - function that add an element into the stack list
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void push_func(stack_t **stack,  unsigned int line_number)
{
	stack_t *node;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	node = malloc(sizeof(stack_t));
	if (!node)
	{   _puts_std(2, "Error: malloc failed");
		free(vars.args);
		closefile(vars.o_opfile);
		exit(EXIT_FAILURE); }
	node->n = vars.number;
	node->prev = NULL;
	node->next = NULL;
	if ((*stack) == NULL)
		(*stack) = node;
	else
	{ node->next = (*stack);
		(*stack)->prev = node;
		(*stack) = node; }
}

/**
 * pall_func - function that print a stack list
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void pall_func(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	if ((*stack))
		for (; tmp; tmp = tmp->next)
			printf("%d\n", tmp->n);

}
/**
 * pint_func - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void pint_func(stack_t **stack, unsigned int line_number)
{

	if (stack == NULL)
		exit(EXIT_FAILURE);

	if (!(*stack))
		{  print_error(line_number, ": can't pint, stack empty", NULL);
		free(vars.args);
		closefile(vars.o_opfile);
		exit(EXIT_FAILURE); }
	if ((*stack))
		printf("%d\n", (*stack)->n);
}

/**
 * pop_func -  removes the top element of the stack.
 * @stack: pointer to stack list
 * @line_number: number of line in file
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	else if (!(*stack))
		{  print_error(line_number, ": can't pop an empty stack", NULL);
		free(vars.args);
		closefile(vars.o_opfile);
		exit(EXIT_FAILURE); }
	else if (!(*stack)->next)
	{	free((*stack));
		(*stack) = NULL;
	}
	else
	{ (*stack)->next->prev = NULL;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	free(tmp);

	}

}
