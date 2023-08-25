#include "monty.h"

/**
  * free_stack - frees a doubly linked list
  * @stack: pointer to the head of the stack
  */
 
void e_free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *te = stack;

		stack = stack->next;
		free(te);
	}
}
