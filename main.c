#include "monty.h"

/**
 *
 *
 *
 */

int main(int argc, char *argv[])
{
		FILE *fp;
		int line_number = 0;
		size_t lenght = 0;
		char *tokens;
		

		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file");
			exit(EXIT_FAILURE);
		}

		fp = fopen(argv[1], "r");
		if (!fp)
		{
			fprintf(stderr, "Error: Can't open file %s", argv[1]);
			exit(EXIT_FAILURE);
		}

		while (getline(&gvar.line, &lenght, gvar.file) != -1)
		{
			line_number++;
			tokens = strtok(gvar.line, " \n\t");
			if (tokens || tokens[0] != '#')
			{
				match_function(tokens, line_number);
			}

		}
		fclose(fp);
		return (EXIT_SUCCESS);
}

/**
 *
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

	free(gvar.line);
}
