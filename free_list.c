#include "monty.h"

/**
 * free_list - free's a stack
 * @head: pointer to head
 */
void free_list(stack_t **head)
{
	stack_t *runner;
	stack_t *tmp;

	if (*head)
	{
		runner = *head;
		*head = NULL;

		while (runner->next)
		{
			tmp = runner;
			runner = runner->next;
			free(tmp);
		}
		free(runner);
	}
}
