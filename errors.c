#include "shell.h"
/**
 *_eputs - check code.
 * @str: char pointer
 */
void _eputs(char *str)
{
	int count = 0;

	if (!str)
	{
		return;
	}
	while (str[count] != '\0')
	{
		_eputchar(str[count]);
		count++;
	}
}

/**
 * _eputchar - check code.
 * @c: char variable
 * Return: 1
 */
int _eputchar(char c)
{
	static int count;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		write(2, buffer, count);
		count = 0;
	}
	if (c != BUF_FLUSH)
		buffer[count++] = c;
	return (1);
}

/**
 * _putfd - check code.
 * @c: char variabe
 * @fd: integer variable
 * Return: 1
 */
int _putfd(char c, int fd)
{
	static int count;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, count);
		count = 0;
	}
	if (c != BUF_FLUSH)
		buffer[count++] = c;
	return (1);
}

/**
 *_putsfd - check code.
 * @str: char pointer
 * @fd: integer variable
 * Return: count value
 */
int _putsfd(char *str, int fd)
{
	int count = 0;

	if (!str)
	{
		return (0);
	}
	while (*str)
	{
		count += _putfd(*str++, fd);
	}
	return (count);
}
