#include "monty.h"

/**
 * execute_opcode - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @p: pointer to monty file
 * 
 * Return: nothing
 */

void e_execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *p)
{
	instruction_t opst[] = {
		{"push", e_push},
		{"pall", e_pall},
		{"pint", e_pint},
		{"pop", e_pop},
		{"swap", e_swap},
		{"add", e_add},
		{"nop", e_nop},

		{NULL, NULL}
		};
	char *op;
	int e, r;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return;

	bus.arg = strtok(NULL, " \n\t");
	for (e = 0; opst[e].opcode; e++)
	{
		for (r = 0; op[r] && opst[e].opcode[r]; r++)
		{
			if (op[r] != opst[e].opcode[r])
				break;
		}
		if (!op[r] && !opst[e].opcode[r])
		{
			opst[e].f(stack, counter);
			return;
		}
	}
	if (op && !opst[e].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(p);
		free(content);
		e_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
