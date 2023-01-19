#include "monty.h"

void unknown_instruction(char *str, unsigned int line_number);
void opcode(stack_t **stack, char *str, unsigned int line_number);

/**
 * opcode - selects the correct function to perform the operation
 * @stack: pointer to the stack
 * @str: string to compare
 * @line_number: line number
 * Return: void
 */
void opcode(stack_t **stack, char *str, unsigned int line_number)
{
	/* index for loop */
	int index = 0;

	/* array of structs */
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}};

	/* check mode stack or queue */
	/* if it's stack, stack mode */
	if (strcmp(str, "stack") == 0)
	{
		global.data_struct = 1;
		return;
	}

	/* if it's queue, queue mode */
	if (strcmp(str, "queue") == 0)
	{
		global.data_struct = 0;
		return;
	}

	/* loop through array of structs */
	while (opcodes[index].opcode != NULL)
	{
		/* if opcode matches, execute function */
		if (strcmp(str, opcodes[index].opcode) == 0)
		{
			opcodes[index].f(stack, line_number);
			return;
		}
		index++;
	}

	/* if opcode doesn't match, print error */
	unknown_instruction(str, line_number);
}

/**
 * unknown_instruction - prints unknown instruction error message and exits
 * @str: string to compare
 * @line_number: line number
 * Return: void
 */
void unknown_instruction(char *str, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}
