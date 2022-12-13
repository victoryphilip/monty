#include "monty.h"

/**
 * stack_mode - change to stack LIFO format
 *
 * @cmd: struct containing useful variables
 */

void stack_mode(cmd_t *cmd)
{
	*cmd->mode = 0;
}

/**
 * queue_mode - change to queue FIFO format
 *
 * @cmd: struct containing useful variables
 */

void queue_mode(cmd_t *cmd)
{
	*cmd->mode = 1;
}
