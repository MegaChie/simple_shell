#include "shell.h"
/**
 * **strtow - check code.
 * @str: char pointer
 * @d: char pointer
 * Return: NULL or s value
 */
char **strtow(char *str, char *d)
{
	int raw, collumn, knife, munch, wordCount = 0;
	char **s;

	if (str == NULL || str[0] == 0)
	{
		return (NULL);
	}
	if (!d)
		d = " ";
	for (raw = 0; str[raw] != '\0'; raw++)
	{
		if (!is_delim(str[raw], d) && (is_delim(str[raw + 1], d) || !str[raw + 1]))
			wordCount++;
	}
	if (wordCount == 0)
		return (NULL);
	s = malloc((1 + wordCount) * sizeof(char *));
	if (!s)
		return (NULL);
	for (raw = 0, collumn = 0; collumn < wordCount; collumn++)
	{
		while (is_delim(str[raw], d))
			raw++;
		knife = 0;
		while (!is_delim(str[raw + knife], d) && str[raw + knife])
			knife++;
		s[collumn] = malloc((knife + 1) * sizeof(char));
		if (!s[collumn])
		{
			for (knife = 0; knife < collumn; knife++)
				free(s[knife]);
			free(s);
			return (NULL);
		}
		for (munch = 0; munch < knife; munch++)
			s[collumn][munch] = str[raw++];
		s[collumn][munch] = 0;
	}
	s[collumn] = NULL;
	return (s);
}

/**
 * **strtow2 - check code.
 * @str: char pointer
 * @d: char variable
 * Return: NULL or s value
 */
char **strtow2(char *str, char d)
{
	int raw, collumn, knife, munch, wordCount = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (raw = 0; str[raw] != '\0'; raw++)
	{
		if ((str[raw] != d && str[raw + 1] == d) ||
		    (str[raw] != d && !str[raw + 1]) || str[raw + 1] == d)
			wordCount++;
	}
	if (wordCount == 0)
		return (NULL);
	s = malloc((1 + wordCount) * sizeof(char *));
	if (!s)
		return (NULL);
	for (raw = 0, collumn = 0; collumn < wordCount; collumn++)
	{
		while (str[raw] == d && str[raw] != d)
			raw++;
		knife = 0;
		while (str[raw + knife] != d && str[raw + knife] && str[raw + knife] != d)
			knife++;
		s[collumn] = malloc((knife + 1) * sizeof(char));
		if (!s[collumn])
		{
			for (knife = 0; knife < collumn; knife++)
				free(s[knife]);
			free(s);
			return (NULL);
		}
		for (munch = 0; munch < knife; munch++)
			s[collumn][munch] = str[raw++];
		s[collumn][munch] = 0;
	}
	s[collumn] = NULL;
	return (s);
}
