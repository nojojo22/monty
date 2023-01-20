#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * parse_file - reads bytecode file and interpretes it commands
 * @filename: file name
 * @stack: top of the stack
 */

void parse_file(char *filename, stack_t **stack)
{
	FILE *fp;
	size_t n = 0;
	int line_count = 1;
	instruction_func s;
	char *line = NULL;
	char *buffer = NULL;
	int check;

	fp = fopen(filename, "r");

	if (!fp)
	{
		printf("Error: Can't open file %s\n", filename);
		err_exit(stack);
	}

	while (getline(&buffer, &n, fp) != -1)
	{
		line = parse(buffer);

		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			err_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(fp);

	if (check == -1)
		exit(-1);
}

/**
 * get_op_func - gets the operation function for opcode
 * given
 * @str: op_code to get it function
 * Return: pointer to the opcode function or NULL
 */
instruction_func get_op_func(char *str)
{
	int i;

	instruction_t instruction[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	i = 0;
	while (instruction[i].f && strcmp(instruction[i].opcode, str) != 0)
		i++;
	return (instruction[i].f);
}

/**
 * parse - search for an opcode in @line
 * @line: the line to be parsed
 * Return: opcode or NULL
 */
char *parse(char *line)
{
	char *opcode;
	char *delim = " \n\t";

	opcode = strtok(line, delim);

	return (opcode);
}
