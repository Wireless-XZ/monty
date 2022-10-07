#include "monty.h"

/**
 * mod_func - finds the modulod of the top two elements of the slack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void mod_func(stack_t **stack, unsigned int line_number)
{
	const stack_t *dummy = *stack;
	unsigned long int len;

	for (len = 0; dummy; len++)
		dummy = dummy->next;

	if (len < 2)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	}
	else if ((*stack)->n == 0)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: division by zero\n", line_number);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		pop_func(stack, line_number);
	}
}

/**
 * pchar_func - prints the char at the top of the stack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void pchar_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	}
	else if (!((*stack)->n >= 0 && (*stack)->n <= 127))
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	}
	else
		printf("%c\n", (*stack)->n);
}

/**
 * pstr_func - prints the string from top of the stack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void pstr_func(stack_t **stack,
	       __attribute__((unused)) unsigned int line_number)
{
	const stack_t *dummy = *stack;

	while (dummy)
	{
		if (!(dummy->n >= 0 && dummy->n <= 127))
		{
			putchar('\n');
			return;
		}
		if (dummy->n == 0)
			break;
		putchar(dummy->n);
		dummy = dummy->next;
	}
	putchar('\n');
}

/**
 * rotl_func - prints the char at the top of the stack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void rotl_func(stack_t **stack,
	       __attribute__((unused)) unsigned int line_number)
{
	stack_t *dummy = *stack, *holder = *stack;

	if (*stack && (*stack)->next)
	{
		while (dummy->next)
			dummy = dummy->next;

		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		dummy->next = holder;
		holder->prev = dummy;
		holder->next = NULL;
	}
}

/**
 * rotr_func - prints the char at the top of the stack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void rotr_func(stack_t **stack,
	       __attribute__((unused)) unsigned int line_number)
{
	stack_t *dummy = *stack;

	if (*stack && (*stack)->next)
	{
		while (dummy->next)
			dummy = dummy->next;

		dummy->next = *stack;
		(*stack)->prev = dummy;
		dummy->prev->next = NULL;
		dummy->prev = NULL;
		*stack = dummy;
	}
}
