#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

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
	int n;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	n = tmp->n;
	while (tmp->next != NULL)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = n;
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
	int n;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;
	n = tmp->n;
	while (tmp->prev != NULL)
	{
		tmp->n = tmp->prev->n;
		tmp = tmp->prev;
	}
	tmp->n = n;
}

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
