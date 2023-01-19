#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	/* let tmp point to the top of the stack */
	stack_t *tmp = *stack;
	/* let line_number be used */
	(void)line_number;

	/* if stack is empty, print a new line */
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	/* loop through the stack until tmp is NULL */
	while (tmp != NULL)
	{
		/* if value n is 0, break or if n is not in ASCII, break */
		if (tmp->n == 0 || tmp->n < 0 || tmp->n > 127)
			break;
		/* print the char at the top of the stack */
		printf("%c", tmp->n);
		/* update tmp */
		tmp = tmp->next;
	}
	/* print a new line */
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	/* let tmp point to the top of the stack */
	stack_t *tmp = *stack;
	/* line_number be used */
	(void)line_number;

	/* if stack is empty or has only one element, return */
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	/* loop through the stack until tmp is NULL */
	while (tmp->next != NULL)
		tmp = tmp->next;

	/* rotate the stack to the top */
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	/* let tmp point to the top of the stack */
	stack_t *tmp = *stack;
	/* declare variable n */
	int n;
	/* line_number be used */
	(void)line_number;

	/* if stack is empty or has only one element, return */
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	/* loop through the stack until tmp is NULL */
	while (tmp->next != NULL)
		tmp = tmp->next;

	/* save the value of the last node */
	n = tmp->n;
	/* while tmp prev is not NULL */
	while (tmp->prev != NULL)
	{
		/* update the value of tmp */
		tmp->n = tmp->prev->n;
		/* update tmp */
		tmp = tmp->prev;
	}
	/* update the value of the first node */
	tmp->n = n;
}
