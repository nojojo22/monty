#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @stack: stack pointer
 * @line_pos: line current position
 * Return: light position
 */

void _pint(stack_t **stack, unsigned int line_pos)
{
	stack_t *tmp;
	(void)line_pos;

	tmp = *stack;
	if (tmp)
	{
		printf("%d\n", tmp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_pos);
		err_exit(stack);
	}
}
