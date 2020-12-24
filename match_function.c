#include "monty.h"
#include <stdlib.h>

/**
 *
 *
 *
 */

int match_function(char *tokens, int line_number)
{
	int i;

	instruction_t functions[] = {
		{"push", _push},
		{"pall", _pall},
		{"NULL", NULL}
	};

	for(i = 0; functions[i].opcode; i++)
	{
		if((strcmp(functions[i].opcode, tokens)) == 0)
			{
				functions[i].f(&gvar.stack, line_number);
				return (0);
			}
	}	
	fprintf(stderr, "L %d: unknown instruction %s", line_number, tokens);
	/*no_leaks();*/
	exit (EXIT_FAILURE);
}

