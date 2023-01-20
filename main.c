#include "dll_helper.h"


/*void print_stack(stack_t *head)
{
	int i = 0;
	if (head == NULL)
	{
		return;
	}
	stack_t *tmp = head;
	while (tmp)
	{
		printf("%d - %d\n", i++, tmp->n);
		tmp = tmp->next;
	}
	return;
}
*/
int main()
{
	stack_t *stack;
	stack = NULL;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		err_exit(&stack);
	}

	// read file to the stack
	parse_file(av[1], &stack);
	free_list(stack);
}