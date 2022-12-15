#include "Shell.h"
/**
 * _memset - check code.
 * @s: char pointre
 * @b: char variable
 * @n: interger variable
 * Return: s value
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int count;

	for (count = 0; count < n; count++)
	{
		s[count] = b;
	}
	return (s);
}

/**
 * ffree - check code.
 * @pp: char double pointer
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
 * _realloc - check code.
 * @ptr: pointer
 * @old_size: unsigned integer variable
 * @new_size: unsigned integer variable
 * Return: functions values, ptr value, 0 or pointer value
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pointer;

	if (ptr == 0)
	{
		return (malloc(new_size))
	}
	if (new_size == 0)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	pointer = malloc(new_size);
	if (pointer == 0)
	{
		return (0);
	}
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		pointer[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);
	return (pointer);
}
