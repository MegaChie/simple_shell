#include "shell.h"
/**
 * is_chain - check code.
 * @info: struct pointer
 * @buf: char pointer
 * @p: struct pointer
 * Return: 0 or 1
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
	{
		return (0);
	}
	*p = j;
	return (1);
}

/**
 * check_chain - check code.
 * @info: struct pointer
 * @buf: char pointer
 * @p: struct pointer
 * @i: struct variable
 * @len: struct variable
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[count] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[count] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
 * replace_alias - check code.
 * @info: struct pointer
 * Return: 0 or 1
 */
int replace_alias(info_t *info)
{
	int count;
	list_t *node;
	char *pointer;

	for (count = 0; count < 10; count++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
		{
			return (0);
		}
		free(info->argv[0]);
		pointer = _strchr(node->str, '=');
		if (!pointer)
		{
			return (0);
		}
		pointer = _strdup(pointer + 1);
		if (!pointer)
		{
			return (0);
		}
		info->argv[0] = pointer;
	}
	return (1);
}

/**
 * replace_vars - check code.
 * @info: struct pointer
 * Return: 0
 */
int replace_vars(info_t *info)
{
	int count = 0;
	list_t *node;

	for (count = 0; info->argv[count]; count++)
	{
		if (info->argv[count][0] != '$' || !info->argv[count][1])
		{
			continue;
		}
		if (!_strcmp(info->argv[count], "$?"))
		{
			replace_string(&(info->argv[count]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[count], "$$"))
		{
			replace_string(&(info->argv[count]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[count][1], '=');
		if (node)
		{
			replace_string(&(info->argv[count]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[count], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - check code.
 * @old: char double pointer
 * @new: char pointer
 * Return: 1
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
