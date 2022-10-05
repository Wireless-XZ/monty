#include "monty.h"

int check_opcode(char *str, stack_t **head, unsigned int *line_no)
{
	int i;
	char *holder = strtok(str, " ");
	instruction_t opp[] = {
		{"push", push_func}, {"pall", pall_func}
	};
	if (holder == NULL)
		return (1);
	for (i = 0; i < 2; i++)
	{
		if (!strcmp(opp[i].opcode, holder))
		{
			if (!strcmp("push", holder))
			{
				opp[i].f(head, *line_no);
				if ((*head)->n == 0)
					return (0);
				return (1);
			}
			else if (!strcmp("pall", holder))
			{
				opp[i].f(head, *line_no);
				return (1);
			}
		}
	}
	fprintf(stderr, "L%d: unknown instructions %s\n", *line_no, holder);
	return (-1);
}

/**
 * get_opcode - gets opcode from file
 * @c: character read from the file
 * @fd: file descriptor
 *
 * Return: potential opcode (string)
 */
char *get_opcode(char c, int fd, unsigned int *ptr)
{
	int i = 0, n = 1, x = 0;

	oP = malloc(sizeof(char) * n);
	if (oP == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	while (c != '\n')
	{
		x = n + 1;
		oP = _realloc(oP, n * sizeof(char), x * sizeof(char));
		if (oP == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (NULL);
		}
		oP[i++] = c;
		oP[n++] = '\0';
		read(fd, &c, 1);
	}
	if (c == '\n')
		(*ptr)++;
	if (x)
		return oP;
	return ("lol");
}

/**
 * main - contains the main body of the program
 * @argc: number of cli arguments
 * @argv: Pointer to cli arguments string
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int fd, y;
	unsigned int line_no = 0;
	char c;
	ssize_t read_len;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		EXIT_FAILURE;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		EXIT_FAILURE;
	}

label:
	read_len = read(fd, &c, 1);

	while (read_len == 1)
	{
		if (c != '\n')
		{
			oP = get_opcode(c, fd, &line_no);
			if (oP == NULL)
				EXIT_FAILURE;
			break;
		}
		else if (c == '\n')
			line_no++;
		read_len = read(fd, &c, 1);
	}
	if (read_len == 1)
	{
		y = check_opcode(oP, &head, &line_no);
		free(oP);
		if (y > 0)
			goto label;
	}
	close(fd);
	free_stack_t(head);
	if (y == 0)
		EXIT_FAILURE;
	return (0);
}
