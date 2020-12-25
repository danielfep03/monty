#include "monty.h"

/**
 *
 *
 *
 */

int is_number(char *text, int line_number)
{
	int i = 0, num;

	if (*text == '-')
		i++;	

	for (; text[i]; i++)
	{
		num = isdigit(text[i]);	
		if (num == 0)
		{
			fprintf(2, "L%d: usage: push integer", line_number);
			exit (EXIT_FAILURE);
		}
			return(0);
	}
}
