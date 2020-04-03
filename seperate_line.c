#include "header.h"

/**
 * seperate_line - seperates a command line into an array of strings
 *                 delimited by a space
 *@line: line to seperate
 *
 * Return: pointer to the array
 */

char **seperate_line(char *line)
{
	char **av;
	char *token;
	int s;

	av = malloc(sizeof(char *)  * 1);
	if (av == NULL)
		return (NULL);
	token = strtok(line, " ");
	s = 0;
	while (token != NULL)
	{
		if (s > 1)
			av = realloc(av, s);
		if (av == NULL)
			return (NULL);
		av[s] = token;
		s++;
		token = strtok(NULL, " ");
	}

	return (av);
}
