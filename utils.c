#include "utils.h"

void err_exit(stack_t **stack)
{
	if (*stack)
	{
		free_list(*stack);
	}
	exit(EXIT_FAILURE);
}
