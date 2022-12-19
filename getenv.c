#include "shell.h"
/**
 * get_environ - check code.
 * @info: Struct pointer
 * Return: function value
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - check code.
 * @info: Struct pointer
 * @var: char pointer
 * Return: 0 or function value 
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *pointer;

	if (!node || !var)
	{
		return (0);
	}
	while (node)
	{
		pointer = starts_with(node->str, var);
		if (pointer && *pointer == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - check code.
 * @info: Struct pointer
 * @var: char pointer
 * @value: char pointer
 * Return: 0 or 1
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *pointer;

	if (!var || !value)
	{
		return (0);
	}
	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
	{
		return (1);
	}
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = info->env;
	while (node)
	{
		pointer = starts_with(node->str, var);
		if (pointer && *pointer == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}
