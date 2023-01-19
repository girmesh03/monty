#include "monty.h"

stack_t *add_node(stack_t **stack, const int n);
stack_t *queue_node(stack_t **stack, const int n);
void free_stack(stack_t *stack);
size_t print_stack(const stack_t *stack);

/**
 * add_node - adds a node to the top of the stack
 * @stack: pointer to the top of the stack
 * @n: value of the new node
 * Return: pointer to the new node
 */
stack_t *add_node(stack_t **stack, const int n)
{
	/* create new node */
	stack_t *new_node = malloc(sizeof(stack_t));

	/* check if malloc failed, if so */
	/* free the new_node and return NULL */
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}

	/* set the new_node's value to n */
	new_node->n = n;
	/* set the new_node's next to stack */
	new_node->next = *stack;
	/* set the new_node's prev to NULL */
	new_node->prev = NULL;

	/* if stack is not NULL */
	/* set the stack's prev to new_node */
	if (*stack)
		(*stack)->prev = new_node;

	/* set stack to new_node */
	*stack = new_node;

	/* return new_node */
	return (new_node);
}

/**
 * queue_node - adds a node to the end of the stack
 * @stack: pointer to the top of the stack
 * @n: value of the new node
 * Return: pointer to the new node
 */
stack_t *queue_node(stack_t **stack, const int n)
{
	/* create new node */
	stack_t *new_node = malloc(sizeof(stack_t));
	/* create current node and set it to stack */
	stack_t *current = *stack;

	/* check if malloc failed, if so */
	/* free the new_node and return NULL */
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		return (NULL);
	}

	/* set the new_node's value to n */
	new_node->n = n;

	/* if stack is NULL */
	/* set the new_node's next to NULL */
	/* set the new_node's prev to NULL */
	/* set stack to new_node */
	if (!*stack)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
		return (new_node);
	}

	/* while current is not NULL */
	while (current)
	{
		/* if current's next is NULL */
		/* set the new_node's next to NULL */
		/* set the new_node's prev to current */
		/* set current's next to new_node */
		if (!current->next)
		{
			new_node->next = NULL;
			new_node->prev = current;
			current->next = new_node;
			break;
		}
		/* set current to current's next */
		current = current->next;
	}

	/* return new_node */
	return (new_node);
}

/**
 * free_stack - frees a stack_t stack
 * @stack: pointer to the top of the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	/* create current node and set it to stack */
	stack_t *current = stack;
	/* create next node */
	stack_t *next;

	/* if stack is not NULL */
	if (stack)
	{
		/* set next to stack's next */
		next = stack->next;
		/* while current is not NULL */
		while (current)
		{
			/* free current */
			free(current);
			/* set current to next */
			current = next;
			/* if next is not NULL */
			if (next)
				/* set next to next's next */
				next = next->next;
		}
	}
}

/**
 * print_stack - prints a stack_t stack
 * @stack: pointer to the top of the stack
 * Return: number of nodes in the stack
 */
size_t print_stack(const stack_t *stack)
{
	/* create current node and set it to stack */
	const stack_t *current = stack;
	/* create counter and set it to 0 */
	size_t counter = 0;

	/* while current is not NULL */
	while (current)
	{
		/* print current's value */
		printf("%d\n", current->n);
		/* set current to current's next */
		current = current->next;
		/* increment counter */
		counter++;
	}

	/* return counter */
	return (counter);
}
