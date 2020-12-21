#include "monty.h"

/**
 * s_pop - deletes last element added
 * @stack: pointer to stack
 * @line_number: number of line being read
 */

void s_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return;
	}

	while (current->next != NULL)
	{
		printf("node int is %d\n", current->n);
		current = current->next;
	}
	printf("node int is %d\n", current->n);

	prev = current->prev;
	printf("prev int is %d\n", prev->n);
	prev->next = NULL;
	free(current);
}

/**
 * nope - really?
 * @stack: stack list
 * @line_number: number of line being read
 */

void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
