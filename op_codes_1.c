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

/**
 * pint_func - prints the item at the top of the stack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop_func - removes the item at the top of the stack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *dummy = *stack;

	if (*stack == NULL)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_number);
	}
	else
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(dummy);
	}
}

/**
 * swap_func - swaps the top two elements of the slack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	const stack_t *dummy = *stack;
	unsigned long int len;
	int x;

	for (len = 0; dummy; len++)
		dummy = dummy->next;

	if (len < 2)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	}
	else
	{
		x = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = x;
	}
}
