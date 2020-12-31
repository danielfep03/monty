#include "monty.h"

/**
 * match_function - Verify a valid argument
 * @tokens: Argument
 * @line_number: Number of the line
 * Return: 0 in success
 */

void match_function(char *tokens, unsigned int line_number)
{
	int i = 0;

	instruction_t functions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};

	while (functions[i].opcode)
	{
		if (strcmp(functions[i].opcode, tokens) == 0)
		{
			functions[i].f(&gvar.stack, line_number);
			break;
		}
		i++;
	}
	if (!functions[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tokens);
		noleaks();
		exit(EXIT_FAILURE);
	}
}

