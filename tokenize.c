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
	char *tok_cpy, *tok = NULL, **args, *line2;
(void)read;
/* 	if (read == -1)
	{
		if (line)
			free(line);
		p_err_getline();
	}
	if (read > 0 && line[read - 1] == '\n')
		line[read - 1] = '\0';
 */
printf("test in strtock alloc\n");
	line2 = _strdup(line);
	if (line2 == NULL)
	{   _puts_std(2, "Error: malloc failed");
		free(line);
		exit(EXIT_FAILURE); }

	tok = strtok(line2, " ");
	tok_cpy = tok;
	for (c = 0; tok; c++)
		tok = strtok(NULL, " ");
	
	free(line2);
	args = (char **)malloc(sizeof(char *) * (c + 1));
	if (args == NULL)
	{   _puts_std(2, "Error: malloc failed");
		free(line);
		exit(EXIT_FAILURE);
	}
	tok_cpy = strtok(line, " ");
	for (i = 0; tok_cpy; i++)
	{
		args[i] = tok_cpy;
		tok_cpy = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (args[0] == NULL)
	{free(args);
	return (NULL); }
	return (args);
}
