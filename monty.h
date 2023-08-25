#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>

#define BUFFER_SIZE 1000

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO, ALX (SE).
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct bus_e - function to hold information
  * @arg: Pointer to the array that holds an argument
  * @file: Pointer to the FILE
  * @content: Pointer to a character array content
  * @lifi: Integer variable to store a value
  * Description: opcode and its function
  */

typedef struct bus_e
{
	char *arg;
	FILE *p;
	char *content;
	int lifi;
} bus_e;
extern bus_e bus;

void e_push(stack_t **stack, unsigned int line_number);
void e_pall(stack_t **stack, unsigned int line_number);
void e_free_stack(stack_t *stack);
void handle_error(unsigned int line_number, const char *message, stack_t *stack, FILE *p);
int main(int argc, char *argv[]);
void e_execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *p);
void e_pint(stack_t **stack, unsigned int line_number);
void e_pop(stack_t **stack, unsigned int line_number);
void e_swap(stack_t **stack, unsigned int line_number);
void e_nop(stack_t **head, unsigned int counter);
void e_add(stack_t **head, unsigned int counter);

#endif
