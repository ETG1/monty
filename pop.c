#include "monty.h"

/**
 * pop - Removes the top element of the stack (pop opcode).
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */

void e_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;

	if (*stack == NULL)
	{
		handle_error(line_number, "can't pop an empty stack", *stack, bus.p);
		return(EXIT_FAILURE);
	}

	*stack = t->next;
	if (t->next != NULL)
	{
		t->next->prev = NULL;
	}
	free(t);
}
