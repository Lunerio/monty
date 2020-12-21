#include "monty.h"

int op_value;

/**
 * run - reads each line and asigns value to global variable
 * @line: Line got from the read function
 * @stack: stack with nodes
 * @line_number: which line it's reading
 * Return: 0 on correc execution, 1 on error
 */

int run(char *line, stack_t **stack, unsigned int line_number)
{
	char *line_tok = NULL;
	char *value = NULL;
	int i = 0;
	char delim[] = " \n\t\n\r";

	instruction_t op_code[] = {
		{"push", add_int},
		{"pall", p_stack},
		{"pint", p_int},
		{NULL, NULL}
	};
	line_tok = strtok(line, delim);
	while (op_code[i].opcode != NULL)
	{
		if (strcmp(op_code[i].opcode, line_tok) == 0)
		{
			if (strcmp(line_tok, "push") == 0)
			{
				value = strtok(NULL, delim);
				if (value == NULL || isdigit(*value) == 0)
				{
					p_error(line_number);
					return (1);
				}
				op_value = atoi(value);
			}
			op_code[i].f(stack, line_number);
			if (*stack == NULL && (strcmp(line_tok, "pint") == 0))
				return (1);
			break;
		}
		i++;
	}
	if (op_code[i].opcode == NULL)
	{
		print_error(line_number, line_tok);
		return (1);
	}
	return (0);
}

/**
 * p_error - prints error in case of incorrect value for push
 * @line_number: number of line that is being read
 */

void p_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
}
