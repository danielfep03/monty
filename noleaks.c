#include "monty.h"

/**
 * noleaks - Function to free memory
 *
 */

void noleaks(void)
{
	stack_t *temp;

	while (gvar.stack)
	{
		temp = gvar.stack->next;
		free(gvar.stack);
		gvar.stack = temp;
	}

	fclose(gvar.file);
	free(gvar.line);
}
