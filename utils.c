#include "utils.h"

/**
 * err_exit - frees the list and exit with failure
 * @stack: pointer to the head of the stack
 */

void err_exit(stack_t **stack)
{
	if (*stack)
	{
		free_list(*stack);
	}
	exit(EXIT_FAILURE);
}

/**
 * _isdigit - checks if @ch is a digit
 * @ch: value to be checked
 * Return: 1 on success, 0 on failure
 */
int _isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')

		return (1);
	else
		return (0);
}

/**
 * isnumber - checks if @str is a number
 * @str: string to check
 * Return: 0 if false, 1 if true
 */
int isnumber(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);

	while (str[i])
	{
		if (str[0] == '-' || _isdigit(str[i]))
		{
			i++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}
