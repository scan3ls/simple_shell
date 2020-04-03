#include "header.h"

/**
 * execute_command - execute a command
 *@pathname: path of command to execute
 *@arg_array: arguments to pass to command
 */

void execute_command(char *pathname, char **arg_array)
{
	int status;
/*	pid_t child_pid = fork();
 */
	if (fork() == 0)
	{
		/* execute command @ pathname w/ arguments in arg_array *
		 * or print an error on failure                         */
		if ((execve(pathname, arg_array, NULL)) == -1)
		{
			printf("Error\n");

		}
	}
	else
	{
		wait(&status);
	}
}
