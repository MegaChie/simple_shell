#include "shell.h"
/**
 * _erratoi - check code.
 * @s: char pointer
 * Return: -1 or result value
 */
int _erratoi(char *s)
{
	int count = 0;
	unsigned long int result = 0;

	if (*s == '+')
	{
		s++;
	}
	for (count = 0;  s[count] != '\0'; count++)
	{
		if (s[count] >= '0' && s[count] <= '9')
		{
			result *= 10;
			result += (s[count] - '0');
			if (result > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
	}
	return (result);
}

/**
 * print_error - check code.
 * @info: struct pointer
 * @estr: char pointer
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - check code.
 * @input: integer variable
 * @fd: integer variable
 * Return: count value
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int raw, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
	{
		__putchar = _eputchar;
	}
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
	{
		_abs_ = input;
	}
	current = _abs_;
	for (raw = 1000000000; raw > 1; raw /= 10)
	{
		if (_abs_ / raw)
		{
			__putchar('0' + current / raw);
			count++;
		}
		current %= raw;
	}
	__putchar('0' + current);
	count++;
	return (count);
}

/**
 * convert_number - check code.
 * @num: long integer variable
 * @base: integer variable
 * @flags: integer variable
 * Return: pte value
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
	{
		*--ptr = sign;
	}
	return (ptr);
}

/**
 * remove_comments - check code.
 * @buf: char pointer
 */
void remove_comments(char *buf)
{
	int count;

	for (count = 0; buf[count] != '\0'; count++)
		if (buf[count] == '#' && (!count || buf[count - 1] == ' '))
		{
			buf[count] = '\0';
			break;
		}
}
