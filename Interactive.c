#include "Shell.h"
/**
 * interactive - check code.
 * @info: list variable
 * Return: 1 or 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check code.
 * @c: char variable
 * @delim: char pointer
 * Return: 1 or 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _isalpha - check code.
 * @c: integer variable
 * Return: 1 or 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * atio - check code.
 * @s: char pointer
 * Return: output value
 */
int _atoi(char *s)
{
	int count, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (count = 0; s[count] != '\0' && flag != 2; count++)
	{
		if (s[count] == '-')
		{
			sign *= -1;
		}
		if (s[count] >= '0' && s[count] >= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[count] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}
	if (sign == -1)
	{
		output = -result;
	}
	else
	{
		output = result;
	}
	return (output);
}
