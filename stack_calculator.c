#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @cmd: access to specific data from command struct
 */

void add(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int sum = 0;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	sum = node_1->n + node_2->n;
	node_2->n = sum;

	pop(cmd);
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void sub(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int diff = 0;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	diff = node_2->n - node_1->n;
	node_2->n = diff;

	pop(cmd);
}

/**
 * divide - divides second top element of the stack with the top element
 * of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void divide(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int quotient;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	if (node_1->n == 0)
	{
		printf("L%d: division by zero\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;
	quotient = node_2->n / node_1->n;
	node_2->n = quotient;
	pop(cmd);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void mul(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int product = 0;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't mul, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	product = node_2->n * node_1->n;
	node_2->n = product;

	pop(cmd);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 *
 * @cmd: access to useful variables from command struct
 */

void mod(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *node_1 = NULL;
	stack_t *node_2 = NULL;
	int rem = 0;

	if (h == NULL || *h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	if (node_1->n == 0)
	{
		printf("L%d: division by zero\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	node_1 = *h;
	node_2 = (*h)->next;

	rem = node_2->n % node_1->n;
	node_2->n = rem;

	pop(cmd);
}
