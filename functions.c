#include "monty.h"

/**
 *
 *
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *stack;
	char *n;
	int num;
   
	n = strtok(NULL, " \n\t");

	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		noleaks();
		exit(EXIT_FAILURE);
	}

	if (!(isdigit(*n)))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		noleaks();
		exit(EXIT_FAILURE);
	}

	num = atoi(n);
	
	if (!*stack)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->n = num;
		*stack = new_node;
	}
	else
	{
		while (temp->next)
			temp = temp->next;

		temp->next = new_node;
		new_node->prev = temp;
		new_node->n = num;
		new_node->next = NULL;
	}
}

/**
 *
 *
 *
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) (line_number);

	if (*stack)
	{
		for (temp = *stack; temp; temp = temp->next)
			printf("%d\n", temp->n);	
	}	
}
