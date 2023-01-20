#include "dll_helper.h"

/**
 * add_node - this function adds an new node to the stack
 * @stack: stack head
 * @n: new item
 * Return: new node or NULL 
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new;

	new = newStackNode(n);
	if (!new)
		return (NULL);

	if (*stack == NULL)
	{
		*stack = new;
		return (*stack);
	}

	(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	new->n = n;

	*stack = new;

	return (*stack);
}

/**
 * add_node_end - adds a stack node to the end of the list
 * @stack: head of the stack
 * @n: new item to add
 * Return: new node or NULL
 */

stack_t *add_node_end(stack_t **stack, const int n)
{
	stack_t *tmp = *stack;
	stack_t *new = NULL;

	new = newStackNode(n);

	if (!new)
		return (NULL);

	if (!(*stack))
	{
		*stack = new;
		return (*stack);
	}

	while (tmp->next)
	{
		tmp = tmp->next;
	}

	new->prev = tmp;
	tmp->next = new;

	return (new);
}

/**
 * free_list - free a list
 * @head: pointer the node to delete
 * Return: void
 */

void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * del_nodeAt - deletes a stack node at an index
 * @stack: head pointer
 * @index: index to the node
 * Return: 0
 */

int del_nodeAt(stack_t **stack, unsigned int index)
{
	stack_t *tmp0;
	stack_t *tmp1;
	stack_t *current;
	unsigned int i = 0;

	if (*stack == NULL)
	{
		return (1);
	}

	tmp0 = *stack;
	if (index == 0)
	{
		*stack = tmp0->next;
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
		free(tmp0); // delete the first node
		return (0);
	}


	// find the node at the index
	i = 0;
	tmp0 = tmp0->next;
	while (i <= index - 1)
	{
		if (tmp0 == NULL)
			return (1);
		i++;
		tmp0 = tmp0->next;
	}
	// stack node to delete
	current = tmp0->next;
	tmp1 = current->next;
	if (tmp1)
		tmp1->prev = current->prev;
	free(current);
	tmp0->next = tmp1;
	return (0);
}
