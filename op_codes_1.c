#include "monty.h"

void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *dummy;
	int i;

	dummy = strtok(NULL, " ");
	if (dummy == NULL)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		return;
	}
	else
	{
		for (i = 0; dummy[i]; i++)
		{
			if (isdigit(dummy[i]) == 0)
			{
				oP = NULL;
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				return;
			}
		}
	}
	new = malloc(sizeof(stack_t));
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
