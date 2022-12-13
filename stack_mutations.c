#include "monty.h"

/**
 * push - adds a new node at the beginning of a stack_t list
 *
 * @cmd: access specific data for command
 * Return: address of new node, or NULL if failed
 */

void push(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *new = NULL;

	if (h == NULL)
	{
		printf("L%d: usage: push integer\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);

	if (*h == NULL)
	{
		new->n = cmd->arg;
		new->next = *h;
		new->prev = NULL;
		*h = new;
		return;
	}
	(*h)->prev = new;
	new->n = cmd->arg;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

/**
 * pop - remove top element of the stack
 *
 * @cmd: access to specific data from command struct
 */

void pop(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *current = NULL;

	if (*h == NULL || h == NULL)
	{
		printf("L%d: can't pop an empty stack\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	current = *h;
	*h = (*h)->next;
	free(current);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @cmd: access to specific data from command struct
 */

void swap(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *third = NULL;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}
	first = *h;
	second = (*h)->next;
	third = second->next;

	first->next = second->next;
	second->next = first;
	third->prev = first;
	first->prev = second;
	second->prev = NULL;
	*h = second;
}

/**
 * rotl - rotates the stack to the top
 *
 * @cmd: access to specific data from command struct
 */

void rotl(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *last = NULL;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	first = *h;
	second = (*h)->next;
	last = *h;

	while (last->next != NULL)
	{
		last = last->next;
	}

	first->next = last->next;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	*h = second;
}

/**
 * rotr - rotates the stack to the bottom
 *
 * @cmd: access to specific data from command struct
 */

void rotr(cmd_t *cmd)
{
	stack_t **h = cmd->head;
	stack_t *first = NULL;
	stack_t *second = NULL;
	stack_t *last = NULL;

	if (*h == NULL || h == NULL || (*h)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", cmd->line_number);
		exit(EXIT_FAILURE);
	}

	first = *h;
	second = *h;
	last = *h;

	while (last->next != NULL)
		last = last->next;

	while (second->next != last)
		second = second->next;

	last->next = first;
	last->prev = first->prev;
	first->prev = last;
	second->next = NULL;
	*h = last;
}
