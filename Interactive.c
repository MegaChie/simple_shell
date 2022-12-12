#include "Shell.h"
/**
 * 
 */
int interactive(info_t *info)//add to h file
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * 
 */
int is_delim(char c, char *delim)//add to h file
{
	while (*delim)
	{
		if (*delim++ == c)
		{
			return (1);//return value here
		}
	}
	return (0);//return value here
}
/**
 * 
 */
int _isalpha(int c)//add to h file
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);//return value here
	}
	else
	{
		return (0);//return value here
	}
}
/**
 * 
 */
int _atoi(char *s)//add to h file
{
	int count, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (count = 0; s[count] != '\0' && flag != 2; count++)
	{
		if (s[count] == -)
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
	return (output);//return value here
}
