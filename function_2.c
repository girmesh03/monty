#include "monty.h"

void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_cnt: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	/* set current to top of stack */
	stack_t *current = *stack;
	/* set temp to top of stack */
	stack_t *temp = *stack;
	/* set temp to next node */
	temp = temp->next;
	/* if stack is empty or has only one node, do nothing */
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	/* swap top two nodes */
	current->next = temp->next;
	current->prev = temp;
	temp->next = current;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_cnt: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_cnt)
{
	/* set current to top of stack */
	stack_t *current = *stack;
	/* set temp to top of stack */
	stack_t *temp = *stack;
	/* set temp to next node */
	temp = temp->next;
	/* if stack is empty or has only one node, do nothing */
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	/* add top two nodes */
	temp->n += current->n;
	/* set top of stack to next node */
	*stack = (*stack)->next;
	/* free top node */
	free(current);
	/* set prev of new top to NULL */
	(*stack)->prev = NULL;
}

/**
 * nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_cnt: line number
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_cnt)
{
	/* line_cnt is unused */
	(void)line_cnt;
	/* stack is unused */
	(void)stack;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the top of the stack
 * @line_cnt: line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_cnt)
{
	/* set current to top of stack */
	stack_t *current = *stack;
	/* set temp to top of stack */
	stack_t *temp = *stack;
	/* set temp to next node */
	temp = temp->next;
	/* if stack is empty or has only one node, do nothing */
	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	/* subtract top two nodes */
	temp->n -= current->n;
	/* set top of stack to next node */
	*stack = (*stack)->next;
	/* free top node */
	free(current);
	/* set prev of new top to NULL */
	(*stack)->prev = NULL;
}
