#include "monty.h"

/**
 * newStackNode - allocate and initialize a new node
 * @n: new item
 * Return: a new node
 */

stack_t *newStackNode(const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new)
	{
		new->next = NULL;
		new->prev = NULL;
		new->n = n;
	}
	return (new);
}
