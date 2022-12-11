#include "Shell.h"
/**
 * 
 */
int _strlen(char *s)
{
	int count = 0;

	if (s == 0)
	{
		return (0);//return value here
	}
	while (*s++)
	{
		count++;
	}
	return (count);//return value here
}

/**
 * 
 */
int _strcmp(char *s1, char *s2)
{
	while (*s2 && *s1)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);//return value here
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);//reruen value here
	}
	else
	{
		return (*s1 < *s2 ? -1 : 1);//return value here
	}
}

/**
 * 
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle++ != *haystack++)
		{
			return (0);
		}
	}
	return ((char *)haystack);
}

/**
 * 
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (ret);//return value here
}
