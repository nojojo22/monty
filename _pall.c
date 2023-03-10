#include "monty.h"

/**
 * _pall - prints all the vaues on the stack
 * @line_num: line number in bytecode file
 * @stack: the stack
 */
void _pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	(void)line_num;

	tmp = *stack;
	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
