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
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	while (tmp != NULL)
	{
		if (tmp->n == 0 || tmp->n < 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
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
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

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
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->prev;
	(*stack)->next->prev = NULL;
	(*stack)->next = NULL;
}
