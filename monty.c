#include "monty.h"

void dummy(void);

/**
 * check_opcode - checks and executes opcode
 * @str: where to check opcode
 * @head: pointer to stack
 * @line_no: line number in the file
 *
 * Return: 1 on success
 */
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
				if (oP[0] == 'x')
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
	fprintf(stderr, "L%d: unknown instruction %s\n", *line_no, holder);
	return (0);
}

/**
 * get_opcode - gets opcode from file
 * @c: character read from the file
 * @fd: file descriptor
 * @ptr: pointer to line number
 *
 * Return: potential opcode (string)
 */
char *get_opcode(char c, int fd, unsigned int *ptr)
{
	int i = 0, n = 1, x = 0;

	printf("c: %c\n", c);
	oP = malloc(sizeof(char) * (n));
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
		return (oP);
	return (NULL);
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
	int fd, y = 0;
	unsigned int line_no = 0;
	char c;
	ssize_t read_len;
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
label:
	read_len = read(fd, &c, 1);

	while (read_len == 1)
	{
		if (c != '\n')
		{
			oP = get_opcode(c, fd, &line_no);
			if (oP == NULL)
				exit(EXIT_FAILURE);
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
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * dummy - to trick betty
 */
void dummy(void)
{
}
