#include "monty.h"

/**
 * match_function - Verify a valid argument
 * @tokens: Argument
 * @line_number: Number of the line
 * Return: 0 in success
 */

int match_function(char *tokens, unsigned int line_number)
{
	int i = 0;
	char *temp = tokens;

	instruction_t functions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"NULL", NULL}
	};

	for (i = 0; functions[i].opcode; i++)
	{
		if (strcmp(functions[i].opcode, temp) == 0)
		{
			functions[i].f(&gvar.stack, line_number);
			return (0);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, temp);
	noleaks();
	exit(EXIT_FAILURE);
}

