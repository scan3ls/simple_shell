#include "header.h"

/**
 * remove_new_line - search a string for new lines and remove them
 *@str: string to search
 *
 * Return: 1 on success, 0 on failure
 */

int remove_new_line(char *str)
{
	int index;

	while (str[0] == ' ')
		str++;

	if (str == NULL || str[0] == '\n')
		return (0);

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == '\n')
			str[index] = 0;
	}
	return (1);
}
