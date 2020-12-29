#include "monty.h"

/**
 * _push - Add new node to the stack
 * @stack: Head of the stack
 * @line_number: Number of the line read
 * Return: No return
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *n = NULL;
	int num = 0;

	n = strtok(NULL, " \n\t");
	if (!n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		noleaks();
		exit(EXIT_FAILURE);
	}
	num = is_number(n, line_number);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		noleaks();
		exit(EXIT_FAILURE);
	}
	if (!*stack)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->n = num;
		*stack = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->n = num;
		new_node->next = *stack;
		*stack = new_node;
	}
}

/**
 * _pall - Function to prints all the stack
 * @stack: Head of the stack
 * @line_number: Number of the line read
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

/**
 * _pint - Print the last element of the satck
 * @stack: head of the stack
 * @line_number: Line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void) (line_number);

	if (*stack)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		noleaks();
		exit(EXIT_FAILURE);
	}
}

/**
 * _pop - Removes the top element of the stack
 * @stack: Head of the stack
 * @line_number: Number of the readed line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
		stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		noleaks();
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	*stack = (*stack)->next;

	free(temp);
}

/**
 * _swap - Swaps the top two elements of the stack
 * @stack:
 * @line_numbe
 */


void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int data = 0;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		noleaks();
		exit(EXIT_FAILURE);
	}
	
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
}
