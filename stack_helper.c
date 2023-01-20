#include "monty.h"

stack_t *newStackNode(const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	new->next = NULL;
	new->prev = NULL;
	new->n = n;

	return new;
}
