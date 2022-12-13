#include "monty.h"

/**
 * pall - prints all elements of a doubly linked list
 *
 * @cmd: data specific variables for command
 */

void pall(cmd_t *cmd)
{
	stack_t *h = *cmd->head;

	if (h == NULL)
		return;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 *
 * @cmd: access to specific data from command struct
 */

void pint(cmd_t *cmd)
{
	stack_t *h = *cmd->head;

	if (h == NULL)
	{
		printf("L%d: can't pint, stack empty\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", h->n);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 *
 * @cmd: access to specific data from command struct
 */

void pchar(cmd_t *cmd)
{
	stack_t *h = *cmd->head;

	if (h == NULL)
	{
		printf("L%d: can't pchar, stack empty\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	if (h->n < 0 || h->n > 127)
	{
		printf("L%d: can't pchar, value out of range\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", h->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @cmd: data specific variables for command
 */

void pstr(cmd_t *cmd)
{
	stack_t *h = *cmd->head;

	if (h == NULL)
		return;

	while (h != NULL && (h->n > 0 && h->n <= 127))
	{
		printf("%c", h->n);
		h = h->next;
	}
	putchar('\n');
}

/**
 * nop - does not do anything
 *
 * @cmd: access to useful variables from command struct
 */

void nop(cmd_t *cmd)
{
	(void) cmd;
}
