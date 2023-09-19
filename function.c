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
int line_count = 0;

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
if (!args)
        continue;
free(line);
line = NULL;
}
free(line);
closefile(o_opfile);
return (0);
}
