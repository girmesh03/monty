#include "monty.h"

void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = n;
}

/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp->next->n += tmp->n;
	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp->next->n -= tmp->n;
	pop(stack, line_number);
}
