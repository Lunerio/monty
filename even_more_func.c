#include "monty.h"

/**
 * div_f - divides the values of the last two elements
 * @stack - you know
 * @l_n: you know
 */

void div_f(stack_t **stack, unsigned int l_n)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	int count = 1, div_value;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l_n);
		exit(EXIT_FAILURE);
	}
	prev = current->prev;
	div_value = prev->n / current->n;
	prev->n = div_value;
	prev->next = NULL;
	free(current);
}


/**
 * mul_f - multiplies the values of the last two elements
 * @stack - you know
 * @l_n: you know
 */

void mul_f(stack_t **stack, unsigned int l_n)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	int count = 1, mul_value;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	prev = current->prev;
	mul_value = prev->n * current->n;
	prev->n = mul_value;
	prev->next = NULL;
	free(current);
}


/**
 * mod_f - gets the rest of division of the last two elements
 * @stack - you know
 * @l_n: you know
 */

void mod_f(stack_t **stack, unsigned int l_n)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	int count = 1, mod_value;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l_n);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", l_n);
		exit(EXIT_FAILURE);
	}
	prev = current->prev;
	mod_value = prev->n % current->n;
	prev->n = mod_value;
	prev->next = NULL;
	free(current);
}
