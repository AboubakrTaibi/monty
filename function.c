#include "monty.h"
#include <stdio.h>
#include <string.h>
/**
 * closefile - function that close file stream.
 * @file: file to close
 */

void closefile(FILE *file)
{

if (fclose(file) == EOF)
{
fprintf(stderr, "Error: Can't close file\n");
exit(EXIT_FAILURE);
}

}
/**
 * main - program that copies the content of a file to another file.
 * @argc: The number of command-line arguments
 * @argv: An array of strings representing the arguments
 * Return: Always 0.
  */
int main(int argc, char *argv[])
{

FILE *o_opfile;
char  *opfile, *line = NULL, **args;
ssize_t read = 0;
int line_count = 0, i;
stack_t *stack;
(void)i;

if (argc != 2)
{ fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE); }

opfile = argv[1];
o_opfile = fopen(opfile, "r");
if (o_opfile == NULL)
{ fprintf(stderr, "Error: Can't open file %s\n", opfile);
exit(EXIT_FAILURE); }

while (fgets(line, 100, o_opfile) != NULL)
{
line_count++;
args = strtok_alloc(line, read);
if (!args || args[0][0] == '#')
    continue;
if (strcmp(args[0], "push") == 0)
{
if (!args[1] || !_atoi(args[1]))
    { print_error(line_count, ": usage: push integer", NULL);
    free(args);
    free(line);
    exit(EXIT_FAILURE); }

}

execute_opcode(&stack, args[0], line_count);
free(line);
free(args);
line = NULL;
}
free(line);
closefile(o_opfile);
return (0);
}
