#include "monty.h"

/**
  * main - Entry point
  * @argc: Number of arguments 
  * @argv: Arguments
  * 
  * Return: Success
  */

bus_e bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	FILE *p = NULL;
	char content[1024], *to;
	size_t size = sizeof(content);
	stack_t *stack = NULL;
	unsigned int counter = 0;
	bus.p = p;

	if (argc != 2 || !(p = fopen(argv[1], "r")))
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	while (fgets(content, size, p))
	{
		counter++;
		if ((to = strtok(content, " \t\n")) && to[0] != '#')
		{
			bus.content = to;
			e_execute_opcode(bus.content, &stack, counter, p);
		}
	}

	fclose(p);
	e_free_stack(stack);
	return (EXIT_SUCCESS);
}
