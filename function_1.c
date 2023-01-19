#include "monty.h"

/* In a file function_1.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

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
void pall(stack_t **stack, unsigned int line_cnt)
{
	/* set current to top of stack */
	stack_t *current = *stack;

	/* line_cnt is unused */
	(void)line_cnt;

	/* if stack is empty, do nothing */
	if (!current)
		return;

	/* loop through stack until current is NULL */
	while (current != NULL)
	{
		/* print value of current */
		printf("%d\n", current->n);
		/* set current to next node */
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: double pointer to the stack
 * @line_cnt: line number of the opcode
 */
void pint(stack_t **stack, unsigned int line_cnt)
{
	/* if stack is empty, print error message */
	/* and exit with status EXIT_FAILURE */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	/* print value at top of stack */
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_cnt: line number of the opcode
 */
void pop(stack_t **stack, unsigned int line_cnt)
{
	/* set tmp to top of stack */
	stack_t *tmp = *stack;

	/* if stack is empty, print error message */
	/* and exit with status EXIT_FAILURE */
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	/* set top of stack to next node */
	*stack = (*stack)->next;
	/* if stack is not empty, set prev of new top to NULL */
	if (*stack != NULL)
		(*stack)->prev = NULL;
	/* free top of stack */
	free(tmp);
}
