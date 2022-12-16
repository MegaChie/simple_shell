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
		dest[count] == src [count];
		count++;
	}
	dest[count] = 0;
	return (dest);
}

/**
 * _strdup - check code.
 * @str: constant char pointer
 * Return: 0 or returnValue value
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *returnValue;

	if (str == 0)
	{
		return (0);
	}
	length = strlen(str);
	returnValue = malloc(sizeof(char) * (length + 1));
	if (returnValue == 0)
	{
		return (0);
	}
	for (length++; length--;)
	{
		returnValue[length] = *--str;
	}
	return (returnValue);
}

/**
 * _puts - check code.
 * @str: char pointer
 */
void _puts(char *str)
{
	int count = 0;

	if (str == 0)
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
	static int count = 0;
	static char buffer[writeBufferSize];
	
	if (c == bufFlush || count >= writeBufferSize)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != bufFlush)
	{
		buffer[count++] = c;
	}
	return (1);
}
