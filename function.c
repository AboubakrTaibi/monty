#include "monty.h"

/**
 * closefile - function that close file stream.
 * @file: file to close
 */

void closefile(FILE *file)
{

if (fclose(file) == EOF)
{
dprintf(STDERR_FILENO, "Error: Can't close file\n");
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
size_t len = 0;
ssize_t read;
int line_count = 0, i;
stack_t *stack;

if (argc != 2)
{ dprintf(STDERR_FILENO, "USAGE: monty file\n");
exit(EXIT_FAILURE); }

opfile = argv[1];
o_opfile = fopen(opfile, "r");
if (o_opfile == NULL)
{ dprintf(STDERR_FILENO, "Error: Can't open file %s\n", opfile);
exit(EXIT_FAILURE); }

while ((read = getline(&line, &len, o_opfile)) != -1)
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
