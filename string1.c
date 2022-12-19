#include "shell.h"
/**
 * _strcpy - check code.
 * @dest: char pointer
 * @src: char pointer
 * Return: dest value
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	if (dest == src || src == 0)
	{
		return (dest);
	}
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = 0;
	return (dest);
}

/**
 * _strdup - check code.
 * @str: char pointer
 * Return: NULL or ret value
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
	{
		length++;
	}
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	{
		return (NULL);
	}
	for (length++; length--;)
	{
		ret[length] = *--str;
	}
	return (ret);
}

/**
 *_puts - check code.
 *@str: char pointer
 */
void _puts(char *str)
{
	int count = 0;

	if (!str)
	{
		return;
	}
	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
}

/**
 * _putchar - check code.
 * @c: char variable
 * Return: 1
 */
int _putchar(char c)
{
	static int count;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		write(1, buffer, count);
		count = 0;
	}
	if (c != BUF_FLUSH)
		buffer[count++] = c;
	return (1);
}
