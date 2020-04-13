#include "header.h"
/**
 * _strcmp - compares two strings using ascii values
 *@s1: first string
 *@s2: second string
 *
 * Return: the differnce, if any, characters in a string
 */

int _strcmp(char *s1, char *s2)
{
	int result = 0;
	int i;

	for (i = 0; !(result) && !(s1[i] == '\0' || s2[i] == '\0'); i++)
		result = s1[i] - s2[i];
	return (result);
}
