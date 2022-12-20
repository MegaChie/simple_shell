#include "shell.h"
/**
 * _myenv - check code.
 * @info: Struct pointer
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - check code.
 * @info: Struct pointer
 * @name: constant car pointer
 * Return: pointer value or NULL
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *pointer;

	while (node)
	{
		pointer = starts_with(node->str, name);
		if (pointer && *pointer)
		{
			return (pointer);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - check code.
 * @info: Struct pointer
 * Return: 1 or 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
	{
		return (0);
	}
	return (1);
}

/**
 * _myunsetenv - check code.
 * @info: Struct pointer
 * Return: 1 or 0
 */
int _myunsetenv(info_t *info)
{
	int count;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (count = 1; count <= info->argc; count++)
	{
		_unsetenv(info, info->argv[count]);
	}
	return (0);
}

/**
 * populate_env_list - check code.
 * @info: Struct pointer
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t count;

	for (count = 0; environ[count]; count++)
	{
		add_node_end(&node, environ[count], 0);
	}
	info->env = node;
	return (0);
}
