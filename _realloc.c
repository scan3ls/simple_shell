#include <string.h>
#include <stdlib.h>

/**
 * _realloc - function that reallocates a memory block using malloc and free
 * @ptr: pointer to the memory
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: new size in bytes of the new memory block
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	unsigned int i;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (NULL);
	}
	nptr = malloc(new_size);
	if (new_size < old_size)
	{
		old_size = new_size;
	}
	for (i = 0; i < old_size; i++)
	{
		nptr[i] = ((char *)ptr)[i];
	}
	free(ptr);
	return (nptr);
}
