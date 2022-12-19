#include "shell.h"
/**
 * *_memset - check code.
 * @s: char pointer
 * @b: char varianble
 * @n: unsigned integer variable
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

	if (!pp)
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
 * Return: ptr value, NULL or pointer value
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pointer;

	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (!new_size)
	{
		return (free(ptr), NULL);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	pointer = malloc(new_size);
	if (!pointer)
	{
		return (NULL);
	}
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
	{
		pointer[old_size] = ((char *)ptr)[old_size];
	}
	free(ptr);
	return (pointer);
}
