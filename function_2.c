#include "monty.h"

/**
 * check_mode - checks if the mode is stack or queue
 * @stack: a pointer to the stack
 * Return: 0 if stack, 1 if queue, 2 if neither
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

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

/**
 * is_number - checks if a string is a number
 * @str: string to check
 * Return: 1 if number, 0 if not
 */
int is_number(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
