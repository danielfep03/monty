#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: Head of the stack
 * @line_number: Number of line read
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int add;  

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		noleaks();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	add = (*stack)->n + (*stack)->next->n;

	(*stack)->next->n = add;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);	
}
