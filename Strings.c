#include "Shell.h"
/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to copy
 * Return: pointer to the resulting string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int raws = 0, collumns;
	char *s = dest;

	while (src[raws] != '\0' && i < n -1)
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
 * 
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
	return (s);//return value here
}

/**
 * 
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);//return value here
		}
		} while (*s++ != '\0');

	return (NULL);//return value here
}
