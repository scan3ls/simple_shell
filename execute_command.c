#include "header.h"

/**
 * execute_command - execute a command
 *@pathname: path of command to execute
 *@arg_array: arguments to pass to command
 *@line: command line to free if exit is called
 */

void execute_command(char **arg_array, char *line, char **tokens)
{
	int status, i, a, b, c, d, r;
	char *error[] = {"/bin/echo", "-n", "Error\n", NULL};
	char *env = *environ;
	char *path = malloc(1);

	/* check for exit command */
	if (strcmp(arg_array[0], "exit") == 0)
	{
		free(arg_array);
		free(line);
		exit(0);
	}

	/* check for env command */
	if (strcmp(arg_array[0], "env") == 0)
	{

		for (i = 1; env != NULL; i++)
		{
			printf("%s\n", env);
			env = *(environ + i);
		}
		return;
	}

	if (fork() == 0)
	{

		/* try to execute function as is */
		r = execve(arg_array[0], arg_array, NULL);
		if (r == -1)
		{
			/* try execve cmd concat to tokens */
			for (i = 0; tokens[i] != NULL; i++)
			{

				/* malloc enough size for path */
				for (a = 0; arg_array[0][a] != '\0'; a++)
					;
				for (b = 0; tokens[i][b] != '\0'; b++)
				        ;
				path = realloc(path, sizeof(char) * (a + b + 1));

				/* path = token + cmd */
				for (c = 0; c < b; c++)
					path[c] = tokens[i][c];
				path[c] = '/';
				c++;
				for (d = 0; d <= a; d++)
					path[c + d] = arg_array[0][d];

				if (execve(path, arg_array, NULL) == -1)
				{

				}

			}
			/* print "error" using echo to close pid */
			free(path);
			execve(error[0], error, NULL);
		}
	}
	else
		wait(&status);
}
