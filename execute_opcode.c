#include "monty.h"

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
	printf("the opcode not valid\n");
}

void push_func(stack_t **stack, unsigned int line_number)
{
    printf("in push function\n");

}
void pall_func(stack_t **stack, unsigned int line_number)
{
    printf("in pall function\n");

}
void pint_func(stack_t **stack, unsigned int line_number)
{
    printf("in pint function\n");
}
void pop_func(stack_t **stack, unsigned int line_number)
{
    printf("in pop function\n");

}
