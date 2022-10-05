#include "monty.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previously allocated memory
 * @old_size: size of the previously allocated memory
 * @new_size: size of the newly allocated memory
 *
 * Return: a pointer to newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i, max = new_size;
	char *oldp = ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size > old_size)
		max = old_size;
	for (i = 0; i < max; i++)
		p[i] = oldp[i];
	free(ptr);
	return (p);
}

/**
 * free_stack_t - frees a doubly linked list
 * @head: head node
 */
void free_stack_t(stack_t *head)
{
	stack_t *dummy = head;

	if (head)
	{
		while (head->next)
		{
			head = head->next;
			free(dummy);
			dummy = head;
		}
	}
	free(dummy);
}
