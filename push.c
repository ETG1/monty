#include "monty.h"

/*
 * push - function to add an element onto the stack
 * @stack: pointer to the stack
 * @line_number - line number of the stack
 * Description: anopcode that pushes elements on to a stack
 * 
 * Return: nothing
 */

void e_push(stack_t **stack, unsigned int line_number)
{
	int val = 0;

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: Memory allocation failed at line %d\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
