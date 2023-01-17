#include "monty.h"

/**
 * free_stack - frees a stack_t list
 * @stack: pointer to the top of the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
