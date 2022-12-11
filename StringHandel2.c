#include "shell.h"
/**
 * 
 */
char *_strcpy(char *dest, char *src)//add to h file
{
	int count = 0;
	if (dest == src || src == 0)
	{
		return (dest);//return value here
	}
	while (src[count])
	{
		dest[count] == src [count];
		count++;
	}
	dest[count] = 0;
	return (dest);//return value here
}

/**
 * 
 */
char *_strdup(const char *str)//add to h file
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
		return (0);//return value here
	}
	for (length++; length--;)
	{
		returnValue[length] = *--str;
	}
	return (returnValue);//return value here
}

/**
 * 
 */
void _puts(char *str)//add to h file
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
 * 
 */
int _putchar(char c)//add to h file
{
	static int count = 0;
	static char buffer = [writeBufferSize];//define in h file

	if (c == bufFlush || count >= writeBufferSize)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != bufFlush)
	{
		buffer[count++] = c;
	}
	return (1);//return value here
}
