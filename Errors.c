#include "Shell.h"
/**
 * 
 */
void _eputs(char *str)
{
	int count = 0;

	if (str == 0)
	{
		return;
	}
	while (str[count] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * Return: 1
 */
int _eputchar (char c)
{
	static int count;
	static char buffer [writeBufferSize];

	if (c == bufFlush || count >= writeBufferSize)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != bufFlush)
	{
		buffer[count++] = c;
	}
	return (1);
}

/**
 * Return: 1
 */
int _putfd(char c, int fileDire)
{
	static int count;
	static char buffer [writeBufferSize];

	if (c == bufFlush || count >= writeBufferSize)
	{
		write(fileDire, buffer, count);
		i = 0;
	}
	if (c != bufFlush)
	{
		buffer[count++] = c;
	}
	return (1);
}

/**
 * Return: 0 or count value
 */
int _putsfd(char *str, int fileDire)
{
	int count = 0;

	if (str == 0)
	{
		return (0);
	}
	while (*str)
	{
		count+= _putfd(*str++,fileDire);
	}
	return (count);
}
