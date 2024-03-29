#include "monty.h"

/**
  * handle_error - Prints the error message along with the line number and
  * additional info (if available), and exits the program with EXIT_FAILURE.
  * @line_number: Line number in the Monty file.
  * @message: Error message to print.
  * @stack: Pointer to the top of the stack.
  * @p: Pointer to the file being processed.
  */

void handle_error(unsigned int line_number, const char *message, stack_t *stack, FILE *p)
{
	fprintf(stderr, "L%d: %s\n", line_number, message);
	e_free_stack(stack);
	if (p)
	{
		fclose(p);
	}
	exit(EXIT_FAILURE);
}
