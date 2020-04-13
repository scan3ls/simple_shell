#include "header.h"

/**
 * main - entry point for custom shell
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t rd;
	char **argv = NULL;
	char **tokens = pathTok();

	/* wait for input */
	printf("$ ");
	/* Ignore signals */
	signal(SIGINT, SIG_IGN);

	while (1)
	{
		rd = getline(&line, &len, stdin);
		/* handles Ctrl+D presses */
		if (rd == -1)
		{
			write(1, "\n", 1);
			break;
		}
		/* remove nl */
		remove_new_line(line);
		/* verify a command is present */
		if (line != NULL && rd > 1)
		{
			/* seperate line into command and arguments */
			argv = seperate_line(line);
			/* execute command */
			execute_command(argv, line, tokens);
		}
		/* reset pathname */
		if (argv != NULL && rd > 1)
			free(argv);
		/* Back to start */
		printf("$ ");
	}
	free(line);
	free(tokens);
	return (0);
}
