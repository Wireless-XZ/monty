#include "monty.h"

void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *dummy;

	dummy = strtok(NULL, " ");
	if (dummy == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
	}
	/* check if value passed to push is int here */
	new = malloc(sizeof(stack_t));

	if (dummy)
	{
		new->n = atoi(dummy);
		new->prev = NULL;
		new->next = NULL;
	}

	if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
}

void pall_func(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	const stack_t *dummy = *stack;

	while (dummy)
	{
		printf("%d\n", dummy->n);
		dummy = dummy->next;
	}
}
