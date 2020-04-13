#include "header.h"

/**
 * execute_command - execute a command
 *@arg_array: arguments to pass to command
 *@line: command line to free if exit is called
 *@tokens: array of directories in PATH
 */

void execute_command(char **arg_array, char *line, char **tokens)
{
	int status;
	int pathCount, cmdLen, pathLen;
	char *error[] = {"/bin/echo", "-n", "Error\n", NULL};
	char *path = malloc(1);

	/*checks for and executes built-ins */
	builtIns(arg_array, line);

	if (fork() == 0)
	{

		/* try to execute function as is */
		if ((execve(arg_array[0], arg_array, NULL)) == -1)
		{
			/* try execve cmd using the different directories in PATH using tokens */
			for (pathCount = 0; tokens[pathCount] != NULL; pathCount++)
			{

				/* find string length of path directory and command */
				/* malloc enough size for new path string */
				cmdLen = getLength(arg_array[0]);
				pathLen = getLength(tokens[pathCount]);
				path = realloc(path, sizeof(char) * (cmdLen + pathLen + 1));

				/* combine path from token to command to get new path */
				/* path = token + "/" + cmd */
				newPath(path, tokens, pathLen, cmdLen, pathCount, arg_array[0]);
				execve(path, arg_array, NULL);
			}
			/* print "error" using echo to close pid */
			free(path);
			execve(error[0], error, NULL);
		}
	}
	else
		wait(&status);
}

/**
 * builtIns - runs builtIns if command is detected
 *@arg_array: command line split into an array (slit at " ")
 *@line: pointer to command line
 */

void builtIns(char **arg_array, char *line)
{
	int i;
	char *env = *environ; /* grabs local enviorn with external variable */
	int letters = 0;      /* counter for printing environ */
	char c[1];

	/* check for exit command */
	if (_strcmp(arg_array[0], "exit") == 0)
	{
		free(arg_array);
		free(line);
		exit(0);
	}

	/* check for env command */
	if (_strcmp(arg_array[0], "env") == 0)
	{

		for (i = 1; env != NULL; i++)
		{
			while ((c[0] = env[letters]) != '\0')
			{
				write(1, c, 1);
			}
			write(1, "\n", 1);
			env = *(environ + i);
		}
		return;
	}
}

/**
 * newPath - create a new path for a command using PATH
 *@path: pointer to the new path
 *@tokens: array of directories from PATH
 *@pathLen: length of current directory from PATH in tokens
 *@cmdLen: length of the command line
 *@pathCount: count of directories in PATH
 *
 * Return: path
 */

void newPath(char *path, char **tokens, int pathLen, int cmdLen, int pathCount, char *cmd)
{
	int newPathTok, newPathCmd; /* index counters to create new path string */

	for (newPathTok = 0; newPathTok < pathLen; newPathTok++)
		path[newPathTok] = tokens[pathCount][newPathTok];

	path[newPathTok] = '/';

	newPathTok++;

	for (newPathCmd = 0; newPathCmd <= cmdLen; newPathCmd++)
		path[newPathTok + newPathCmd] = cmd[newPathCmd];
}

/**
 * getLength - find length of a string
 *@str: target string
 *
 * Return: length of str
 */

int getLength(char *str)
{
	int index;

	for (index = 0; str[index] != '\0'; index++)
		;
	return (index);
}
