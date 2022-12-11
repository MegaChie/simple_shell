#include "Shell.h"
/**
 * 
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count;

	for (count = 0; count < n; count++)
	{
		s[count] = b;
	}
	return (s);//return value here
}

/**
 * 
 */
void ffree(char **pp)
{
	char **a = pp;

	if (pp == 0)
	{
		return;
	}
	while (*pp)
	{
		free(*pp++);
	}
	free(a);
}

/**
 * 
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pointer;

	if (ptr == 0)
	{
		return (malloc(new_size));//return value here
	}
	if (new_size == 0)
	{
		return (free(ptr), NULL);//return value here
	}
	if (new_size == old_size)
	{
		return (ptr);//return value here
	}
	pointer = malloc(new_size);
	if (pointer == 0)
	{
		return (0);//return value here
	}
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		pointer[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);
	return (pointer);//return value here
}
