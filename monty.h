#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct cmd_s - command struct
 * @op: name of operation
 * @arg: argument for function
 * @mode: stack or queue mode
 * @line_number: number of line being evaluated
 * @head: head of linked list
 * @tail: tail of linked list
 */
typedef struct cmd_s
{
	char *op;
	int arg;
	int *mode;
	unsigned int line_number;
	stack_t **head;
	stack_t **tail;
} cmd_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(cmd_t *cmd);
} instruction_t;

void eval(char *line, stack_t **h, stack_t **t, int *mode, unsigned int ln);
int parse(char *line, cmd_t *cmd);
void run(cmd_t *cmd);
void push(cmd_t *cmd);
void pall(cmd_t *cmd);
void pint(cmd_t *cmd);
void pop(cmd_t *cmd);
void swap(cmd_t *cmd);
void add(cmd_t *cmd);
void nop(cmd_t *cmd);
void sub(cmd_t *cmd);
void divide(cmd_t *cmd);
void mul(cmd_t *cmd);
void mod(cmd_t *cmd);
void pchar(cmd_t *cmd);
void pstr(cmd_t *cmd);
void rotl(cmd_t *cmd);
void rotr(cmd_t *cmd);
#endif /*MONTY_H*/
