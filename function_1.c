#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_cnt: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	/* get argument */
	char *value = global.argument;

	/* if value is not a digit */
	if ((is_digit(value)) == 0)
	{
		/* print error message */
		fprintf(stderr, "L%u: usage: push integer\n", line_cnt);
		/* exit with status EXIT_FAILURE */
		exit(EXIT_FAILURE);
	}

	/* if stack mode is stack, push to stack */
	if (global.data_struct == 1)
	{
		/* if push fails, exit with status EXIT_FAILURE */
		if (!add_node(stack, atoi(global.argument)))
			exit(EXIT_FAILURE);
	}

	/* if stack mode is queue, push to queue */
	if (global.data_struct == 0)
	{
		/* if push fails, exit with status EXIT_FAILURE */
		if (!queue_node(stack, atoi(global.argument)))
			exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the top of the stack
 * @line_cnt: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}
