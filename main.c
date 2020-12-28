#include "monty.h"

/**
 * main - Monty interpreter
 * @argc: Number of argument
 * @argv: Monty file
 * Return: 1 In Success
 */

int main(int argc, char *argv[])
{
		unsigned int line_number = 0;
		size_t lenght = 0;
		char *tokens = NULL;
		
		gvar.stack = NULL;
		gvar.line = NULL;
		gvar.file = NULL;

		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}

		gvar.file = fopen(argv[1], "r");
		if (!gvar.file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		while (getline(&gvar.line, &lenght, gvar.file) != EOF)
		{
			line_number++;
			if (gvar.line)
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


