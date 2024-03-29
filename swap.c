#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack (swap opcode).
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty file.
 */

void e_swap(stack_t **stack, unsigned int line_number)
{
	int te;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		handle_error(line_number, "can't swap, stack too short", *stack, bus.p);
		return;
	}
	te = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = te;
}
