#include "monty.h"

globals_var vars;

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

	char  *opfile, line[BUF_SIZE] = {'\0'};
	ssize_t read = 0;
	int line_count = 0, i;
	stack_t *stack = NULL;
	(void)i;

	if (argc != 2)
	{ fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }

	opfile = argv[1];
	vars.o_opfile = fopen(opfile, "r");
	if (vars.o_opfile == NULL)
	{ fprintf(stderr, "Error: Can't open file %s\n", opfile);
		exit(EXIT_FAILURE); }

	while (fgets(line, sizeof(line), vars.o_opfile) != NULL)
	{
		line_count++;
		vars.args = strtok_alloc(line, read);
		if (!vars.args || vars.args[0][0] == '#')
			continue;
		if (strcmp(vars.args[0], "push") == 0)
			vars.number = _atoi(vars.args[1], stack, line_count);

		execute_opcode(&stack, vars.args[0], line_count);
		free(vars.args);
	}
	free_stack(stack);
	closefile(vars.o_opfile);
	return (0);
}
