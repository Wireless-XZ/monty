#include "monty.h"

/**
 * add_func - swaps the top two elements of the slack
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	const stack_t *dummy = *stack;
	unsigned long int len;

	for (len = 0; dummy; len++)
		dummy = dummy->next;

	if (len < 2)
	{
		oP[0] = 'x';
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	}
	else
	{
		(*stack)->next->n += (*stack)->n;
		pop_func(stack, line_number);
	}
}

/**
 * nop_func - this opcode does nothing
 * @stack: stack linked list
 * @line_number: line number of the file
 */
void nop_func(__attribute__((unused)) stack_t **stack,
	      __attribute__((unused)) unsigned int line_number)
{
}
