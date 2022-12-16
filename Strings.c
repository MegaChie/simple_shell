#include "Shell.h"
/**
 * _strncpy - check code.
 * @dest: char pointer
 * @src: char pointer
 * @n: integer variable
 * Return: s value
 */
char *_strncpy(char *dest, char *src, int n)
{
	int raws = 0, collumns;
	char *s = dest;

	while (src[raws] != '\0' && i < n - 1)
	{
		src[raws] = dest[raws];
		raws++;
	}
	if (raws < n)
	{
		collumns = raws;
		while (collumns < n)
		{
			dest[collumns] = '\0';
			collumns++;
		}
	}
	return (s);
}

/**
 * _strncat - check code.
 * @dest: char pointer
 * @src: char pointer
 * @n: integer variable
 * Return: s value
 */
char *_strncat(char *dest, char *src, int n)
{
	int raws = 0, collumns = 0;
	char *s = dest;

	raws = strlen(dest);
	while (src[collumns] != '\0' && collumns < n)
	{
		dest[raws] = src[collumns];
		raws++;
		collumns++;
	}
	if (collumns < n)
	{
		dest[raws] = '\0';
	}
	return (s);
}

/**
 * _strchr - check code.
 * @s: char pointer
 * @c: char variable
 * Return: s or 0
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
		} while (*s++ != '\0');
	return (0);
}
