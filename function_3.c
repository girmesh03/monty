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
	/* let tmp point to the top of the stack */
	stack_t *tmp = *stack;

	/* if stack is empty or has only one element, print error message */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* if the top element of the stack is 0, print error message */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* divide the second top element of the stack by the top element */
	tmp->next->n /= tmp->n;
	/* remove the top element of the stack */
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void mul(stack_t **stack, unsigned int line_number)
{
	/* let tmp point to the top of the stack */
	stack_t *tmp = *stack;

	/* if stack is empty or has only one element, print error message */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* multiply the second top element of the stack with the top element */
	tmp->next->n *= tmp->n;
	/* remove the top element of the stack */
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
	/* let tmp point to the top of the stack */
	stack_t *tmp = *stack;

	/* if stack is empty or has only one element, print error message */
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* if the top element of the stack is 0, print error message */
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* compute the rest of the division of the second top element of the */
	/* stack by the top element */
	tmp->next->n %= tmp->n;
	/* remove the top element of the stack */
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
	/* if stack is empty, print error message */
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* if the value at the top of the stack is not an ASCII character, */
	/* print error message */
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* print the char at the top of the stack, followed by a new line */
	printf("%c\n", (*stack)->n);
}
