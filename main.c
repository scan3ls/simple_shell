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
	char *path = NULL;

	/* wait for input */
	printf("$ ");
	/* Ignore signals */
	signal(SIGINT, SIG_IGN);

	while (1)
	{
		rd = getline(&line, &len, stdin);
		/* handles Ctrl+D presses */
		if (rd == -1)
			continue;
		/* remove nl */
		remove_new_line(line);
		/* verify a command is present */
		if (line != NULL && rd > 1)
		{
			/* seperate line into command and arguments */
			argv = seperate_line(line);
			/* find command assume base path of /bin/*/
			path = find_command_path(argv[0]);
			/* execute command */
			execute_command(path, argv, line);
		}
		/* reset pathname */
		if (path != NULL && rd > 1)
			free(path);
		if (argv != NULL && rd > 1)
			free(argv);
		/* Back to start */
		printf("$ ");
	}
	free(line);

	return (0);
}
