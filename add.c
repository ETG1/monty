#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 *
 * Return: nothing
*/

void e_add(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int len = 0, a;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.p);
		free(bus.content);
		e_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	a = hd->n + hd->next->n;
	hd->next->n = a;
	*head = hd->next;
	free(hd);
}
