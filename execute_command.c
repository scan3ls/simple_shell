#include "header.h"

/**
 * execute_command - execute a command
 *@pathname: path of command to execute
 *@arg_array: arguments to pass to command
 *@line: command line to free if exit is called
 */

void execute_command(char *pathname, char **arg_array, char *line)
{
	int status, i;
	char *error[] = {"/bin/echo", "-n", "Error\n", NULL};
	char *env = *environ;

	/* check for exit command */
	if (strcmp(arg_array[0], "exit") == 0)
	{
		free(pathname);
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
		/* execute command @ pathname w/ arguments in arg_array */
		/* or print an error on failure */
		if ((execve(pathname, arg_array, NULL)) == -1)
		{
			/* will print "error" using echo to close pid */
			execve(error[0], error, NULL);
		}
	}
	else
		wait(&status);
}
