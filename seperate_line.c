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
	char **av = malloc(sizeof(char *) * 15);
	char *token;
	int s;

	if (line == NULL)
		return (NULL);
	while (line[0] == ' ')
		line++;

	token = strtok(line, " ");
	s = 0;
	while (token != NULL)
	{
		av[s] = token;
		s++;
		token = strtok(NULL, " ");
	}
	/* av[s] = NULL; */

	return (av);
}
