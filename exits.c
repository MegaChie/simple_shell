#include "shell.h"

/**
 * *_strncpy - check code.
 * @dest: char pointer
 * @src: char pointer
 * @n: integer variable
 * Return: s value
 */
char *_strncpy(char *dest, char *src, int n)
{
	int raw, collumn;
	char *s = dest;

	raw = 0;
	while (src[raw] != '\0' && raw < n - 1)
	{
		dest[raw] = src[raw];
		raw++;
	}
	if (raw < n)
	{
		collumn = raw;
		while (collumn < n)
		{
			dest[collumn] = '\0';
			collumn++;
		}
	}
	return (s);
}

/**
 * *_strncat - ccheck code.
 * @dest: char pointer
 * @src: char pointer
 * @n: integer variable
 * Return: s value
 */
char *_strncat(char *dest, char *src, int n)
{
	int raw, collumn;
	char *s = dest;

	raw = 0;
	collumn = 0;
	while (dest[raw] != '\0')
	{
		raw++;
	}
	while (src[collumn] != '\0' && collumn < n)
	{
		dest[raw] = src[collumn];
		raw++;
		collumn++;
	}
	if (collumn < n)
	{
		dest[raw] = '\0';
	}
	return (s);
}

/**
 * *_strchr - check code.
 * @s: char pointer
 * @c: char variable
 * Return:  s value or NULL
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
	} while (*s++ != '\0');
	return (NULL);
}
