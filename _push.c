#include "monty.h"

/**
 * _push - adds a value to a stack
 * if s_flag == 0, use stack
 * else use queue
 * @stack: a pointer the to stack
 * @line_num: current line in the bytecode file
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_num)
{
	char *arg;
	int push_arg;

	push_arg = 0;

	arg = strtok(NULL, " \n\t");
	if (isnumber(arg))
	{
		push_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		err_exit(stack);
	}

	/* use as a stack ds */
	add_node(stack, push_arg);
}
