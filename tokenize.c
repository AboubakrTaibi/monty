#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * strtok_alloc - Tokenizes a given string based on space delemitor (" ")
 *				 and allocates memory for tokens
 * @line: The input line
 * @read: The number of characters read from the line
 *
 * Return: A double pointer to an array of strings containing the tokens
 *         NULL is returned on failure
 */
char **strtok_alloc(char *line, ssize_t read)
{
	int c = 0, i;
	char *tok_cpy, *tok = NULL, **arguments, *line2;
(void)read;
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';
	line2 = _strdup(line);
	if (line2 == NULL)
	{   _puts_std(2, "Error: malloc failed");
		exit(EXIT_FAILURE); }

	tok = strtok(line2, " ");
	tok_cpy = tok;
	for (c = 0; tok; c++)
		tok = strtok(NULL, " ");

	free(line2);
	arguments = (char **)malloc(sizeof(char *) * (c + 1));
	if (arguments == NULL)
	{   _puts_std(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	tok_cpy = strtok(line, " ");
	for (i = 0; tok_cpy; i++)
	{
		arguments[i] = tok_cpy;
		tok_cpy = strtok(NULL, " ");
	}
	arguments[i] = NULL;

	if (arguments[0] == NULL)
	{free(arguments);
	return (NULL); }
	return (arguments);
}
