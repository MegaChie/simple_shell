#include "shell.h"
/**
 * _myhistory - check code.
 * @info: Structure pointer
 * Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - check code.
 * @info: struct pointer
 * @str: char pointer
 * Return: 1 or ret value
 */
int unset_alias(info_t *info, char *str)
{
	char *pointer, c;
	int ret;

	pointer = _strchr(str, '=');
	if (!pointer)
	{
		return (1);
	}
	c = *pointer;
	*pointer = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pointer = c;
	return (ret);
}

/**
 * set_alias - check code.
 * @info: struct pointer
 * @str: char pointer
 * Return: 1 or function value
 */
int set_alias(info_t *info, char *str)
{
	char *pointer;

	pointer = _strchr(str, '=');
	if (!pointer)
	{
		return (1);
	}
	if (!*++pointer)
	{
		return (unset_alias(info, str));
	}
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - check code.
 * @node: struct pointer
 * Return: 0 or 1
 */
int print_alias(list_t *node)
{
	char *pointer = NULL, *a = NULL;

	if (node)
	{
		pointer = _strchr(node->str, '=');
		for (a = node->str; a <= pointer; a++)
		{
			_putchar(*a);
		}
		_putchar('\'');
		_puts(pointer + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - check code.
 * @info: Structure pointer
 * Return: 0
 */
int _myalias(info_t *info)
{
	int count = 0;
	char *pointer = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (count = 1; info->argv[count]; count++)
	{
		pointer = _strchr(info->argv[count], '=');
		if (pointer)
		{
			set_alias(info, info->argv[count]);
		}
		else
		{
			print_alias(node_starts_with(info->alias, info->argv[count], '='));
		}
	}
	return (0);
}
