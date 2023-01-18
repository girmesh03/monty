#define _POSIX_C_SOURCE 200809L
#include "monty.h"

void usage_error(void);
void open_error(char *filename);
void unknown_instruction(char *opcode, unsigned int line_number);

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}};
	int i;

	if (argc != 2)
	{
		usage_error();
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		open_error(argv[1]);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		token = strtok(line, " \n\t");
		if (token == NULL || token[0] == '#' || token[0] == '\n')
			continue;
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(token, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (opcodes[i].opcode == NULL)
		{
			unknown_instruction(token, line_number);
		}
	}
	free(line);
	free_stack(stack);
	fclose(fp);
	return (0);
}

/**
 * usage_error - prints usage error message
 * Return: void
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_error - prints open error message
 * @filename: name of file
 * Return: void
 */
void open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction - prints unknown instruction error message
 * @opcode: opcode
 * @line_number: line number
 * Return: void
 */
void unknown_instruction(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
