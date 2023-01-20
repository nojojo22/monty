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
int main(int argc, char **argv)
{
	stack_t *stack;
	stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		err_exit(&stack);
	}

	parse_file(argv[1], &stack);
	free_list(stack);

	return (0);
}
