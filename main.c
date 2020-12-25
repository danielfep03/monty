#include "monty.h"

/**
 *
 *
 *
 */

int main(int argc, char *argv[])
{
		int line_number = 0;
		size_t lenght = 0;
		char *tokens;
		

		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file");
			exit(EXIT_FAILURE);
		}

		gvar.file = fopen(argv[1], "r");
		if (!gvar.file)
		{
			fprintf(stderr, "Error: Can't open file %s", argv[1]);
			exit(EXIT_FAILURE);
		}

		while (getline(&gvar.line, &lenght, gvar.file) != EOF)
		{
			line_number++;
			if(gvar.line)
			{
				tokens = strtok(gvar.line, " \n\t");
			
				if (tokens)
				{
					match_function(tokens, line_number);
				}
			}

		}
		noleaks();
		return (EXIT_SUCCESS);
}


