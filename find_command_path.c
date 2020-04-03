#include "header.h"

/**
 * find_command_path - find the command path for a given command
 *@command: command given
 *
 * Return: pointer that holds the command path
 */

char *find_command_path(char *command)
{
	int c;
	char *bin = "/bin/";
	char *bash = "/bin/bash";
	char *found;
	char *pathname;

	(void)bash;

	/* If command is already a path */
	/* return command */

	/* Allocate and check if failed */
	pathname = malloc(sizeof(char) * 100);
	if (pathname == NULL)
	{
		return (NULL);
	}

	/*try to find command in bin or bash*/
	found = bin;

	/* Set pathname to the command path */
	for (c = 0; found[c] != '\0'; c++)
	{
		pathname[c] = found[c];
	}

	/* only if command not path is given */
	strcat(pathname, command);

	return (pathname);
}
