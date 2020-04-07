#include "header.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **argv;
	char *path;

	/* wait for input */
	printf("$ ");
	signal(SIGINT, SIG_IGN);

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		/* remove nl */
		remove_new_line(line);

		if (line != NULL && read > 1)
		{
			/* seperate line into command and arguments */
			argv = seperate_line(line);
			/* find command assume base path of /bin/*/
			path = find_command_path(argv[0]);
			/* execute command */
			execute_command(path, argv);
			/* reset pathname */
			free(path);
			free(argv);
		}
		/* Back to start */
		printf("$ ");
	}

	free(line);
}
