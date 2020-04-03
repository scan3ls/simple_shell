#include "header.h"

/**
 * remove_new_line - search a string for new lines and remove them
 *@str: string to search
 */

void remove_new_line(char *str)
{
	char  *charp; /* Holds index of str that is /n */

	charp = strchr(str, '\n');
	if (charp) /* May break if \n is needed */
		*charp = 0;
}
