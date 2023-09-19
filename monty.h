#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void closefile(FILE *file);
char **strtok_alloc(char *line, ssize_t read);
void print_number(int std, int n);
int _puts(char *c);
int _atoi(char *s);
int _puts_std(int std, char *str);
int _slen(char *s);
int p_err_getline(void);
void p_err_write(int w);
void print_error(int line_number, char *err_msg, char *opcode);


#endif /* MONTY_H */
