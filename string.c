#include "shell.h"
/**
 * _strlen - check code.
 * @s: char pointer
 * Return: count value
 */
int _strlen(char *s)
{
	int count = 0;

	if (!s)
	{
		return (0);
	}
	while (*s++)
	{
		count++;
	}
	return (count);
}

/**
 * _strcmp - check code.
 * @s1: char pointer
 * @s2: char pointer
 * Return: comparisons values or 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 < *s2 ? -1 : 1);
	}
}

/**
 * starts_with - check code.
 * @haystack: constant char pointer
 * @needle: constant char pointer
 * Return: function value
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}

/**
 * _strcat - check code.
 * @dest: char pointer
 * @src: char pointer
 * Return: ret value
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (ret);
}
