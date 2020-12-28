#include "monty.h"

/**
 * is_number - Verifi if *number is a number
 * @number: Char to verify
 * @line_number: Number of the read line
 * Return: A int
 */

int is_number(char *number, int line_number)
{
	int i = 0, num;

	if (number[0] == '-')
		i++;

	for (; number[i]; i++)
	{
		num = isdigit(number[i]);
		if (num == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			noleaks();
			exit(EXIT_FAILURE);
		}
	}
	num = 0;
	num = atoi(number);
	return (num);
}
