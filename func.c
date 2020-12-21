#include "monty.h"

/**
 * add_int - add node at the end of stack
 * @stack: pointer to first element
 * @line_number: line being read
 */

void add_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *act = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
			return;
		new->n = op_value;
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
		return;
	}
	else
	{
		while (act->next != NULL)
		{
			act = act->next;
		}
		new = malloc(sizeof(stack_t));
		if (new == NULL)
			return;
		new->n = op_value;
		new->prev = act;
		new->next = NULL;
		act->next = new;
	}
}

/**
 * p_stack - print elements of the stack, from the last one added
 * @stack: pointer to stack
 * @line_number: number of line being read
 */

void p_stack(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		return;

	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}
	while ((*stack)->prev != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->prev;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * free_stack - free memory of stack before finishing program
 * @stack: pointer to first element
 */

void free_stack(stack_t *stack)
{
	stack_t *save = stack;

	if (stack == NULL)
	{
		return;
	}
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	while (stack != NULL)
	{
		save = stack;
		stack = stack->prev;
		free(save);
	}
}

/**
 * print_error - print error in case that the line doesn't have correct op_code
 * @line_number: line number being read
 * @op_c: command being read
 */

void print_error(unsigned int line_number, char *op_c)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op_c);
}
