#ifndef MONTY_HEADER
#define MONTY_HEADER
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *next;
	struct stack_s *prev;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int s_flag;

typedef void (*instruction_func)(stack_t **stack, unsigned int line_number);

stack_t *newStackNode(const int n);

void parse_file(char *filename, stack_t **stack);
char *parse(char *line);
instruction_func get_op_func(char *str);

int _isdigit(int n);
int isnumber(char *val);
stack_t *add_node_end(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
void free_list(stack_t *stack);
int del_nodeAt(stack_t **stack, unsigned int index);

void err_exit(stack_t **stack);

void _push(stack_t **stack, unsigned int line_num);
void _pall(stack_t **stack, unsigned int line_num);
void _pint(stack_t **stack, unsigned int line_pos);

#endif
