#include "monty.h"

/**
* e_pint -prints  the value at the top of the stack (pint opcode).
* @stack: Pointer to the top of the stack.
* @line_number: Line number in the Monty file.
*/

void e_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tp = *stack;

	(void)line_number;

	if (tp == NULL)
	{
		handle_error(line_number, "can't pint, stack empty", *stack, bus.p);
	}
	printf("%d\n", tp->n);
}
