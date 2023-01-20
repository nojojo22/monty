#ifndef DLL_HELPER
#define DLL_HELPER

#include "monty.h"

stack_t *add_node_end(stack_t **stack, const int n);
stack_t *add_node(stack_t **stack, const int n);
void free_list(stack_t *stack);
int del_nodeAt(stack_t **stack, unsigned int index);

#endif
