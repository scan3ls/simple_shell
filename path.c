#include "header.h"
/**
 *pathTok - split Path into Tokens
 *Return: Tokens
 */

char **pathTok(void)
{
	char **tokens = NULL;
	char *tok = NULL;
	int i;
	char *path = NULL;
	char *env = *environ;

	for (i = 0; env != NULL; i++)
	{
		if (env[0] == 'P' && env[1] == 'A')
			break;
		env = *(environ + i);
	}
	path = _strdup(env + 5);
	i = 0;

	tokens = malloc(1000);

	tok = strtok(path, ":");
	while (tok != NULL)
	{
		tokens[i] = tok;
		i++;
		tok = strtok(NULL, ":");
	}
	tokens[i] = NULL;
	free(path);
	return (tokens);
}
/**
 * _strdup  - allocate memory for a copy of a string
 *@str: source string
 *
 * Return: pointer to copy of the source string
 */

char *_strdup(char *str)
{
	/*Create pointer, index counter, and source string length variable.*/
	char *p = NULL;
	int index = 0;
	int strlen = 0;

	/*Verify valid string*/
	if (str == NULL)
	{
		return (NULL);
	}

	/*Find string length and allocate enough memory at pointer p*/
	strlen = getLength(str);
	p = malloc(sizeof(char) * strlen);

	/*Verify if malloc was successful*/
	if (p == NULL)
	{
		return (NULL);
	}

	/*Copy string str to memory position @ p*/
	for (index = 0; index < strlen; index++)
	{
		*(p + index) = *(str + index);
	}

	return (p);
}
