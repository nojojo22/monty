#include "monty.h"

/**
 * main - entry point of the program
 * @argc: number of command line arguments.
 * @argv: array of command line arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		err_exit(&stack);
	}

	parse_file(argv[1], &stack);
	free_list(stack);

	return (0);
}
