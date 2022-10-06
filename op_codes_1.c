#include "monty.h"

/**
 * push_func - pushes an item to the stack
 * @stack: pointer to a linked list stack
 * @line_number: file's line number
 */
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
				oP[0] = 'x';
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

/**
 * pall_func - prints all the items on the stack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void pall_func(stack_t **stack,
	       __attribute__((unused)) unsigned int line_number)
{
	const stack_t *dummy = *stack;

	while (dummy)
	{
		printf("%d\n", dummy->n);
		dummy = dummy->next;
	}
}
