#include "monty.h"

void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

/**
 * divi - divides the second top element of the stack by the top element
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void divi(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->next->n /= tmp->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->next->n *= tmp->n;
	pop(stack, line_number);
}

/**
 * mod - computes the rest of the division of the second top element of the
 * stack by the top element
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->next->n %= tmp->n;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	/* if stack is empty, print error */
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* if the value is in the ascii table, print the char */
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		fprintf(stdout, "%c\n", (*stack)->n);
	else
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
}
