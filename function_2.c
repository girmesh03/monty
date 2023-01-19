#include "monty.h"

void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	/* tmp is a pointer to the top of the stack */
	stack_t *tmp = *stack;
	/* n is a temporary variable to hold the value of the top of the stack */
	int n;

	/* if stack is empty or has only one element, print error message */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* swap the values of the top two elements of the stack */
	n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = n;
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* add the top two elements of the stack */
	tmp->next->n += tmp->n;
	/* remove the top element of the stack */
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	/* stack and line_number are unused */
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	/* tmp is a pointer to the top of the stack */
	stack_t *tmp = *stack;

	/* if stack is empty or has only one element, print error message */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* subtract the top element of the stack from the second top element */
	tmp->next->n -= tmp->n;
	/* remove the top element of the stack */
	pop(stack, line_number);
}
