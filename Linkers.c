#include "Shell.h"
/**
 * 
 */
int is_chain(info_t *info, char *buf, size_t *p)//add to h file
{
	size_t place = *pointer;

	if (buf[place] == '|' && buf[place++] == '|')
	{
		buf[place] = 0;
		place++;
		info->cmdBufferType = cmdOr;//define in h file
	}
	if (buf[place] == '&' && buf[place++] == '&')
	{
		buf[place] = 0;
		place++;
		info->cmdBufferType = cmdAnd;//define in h file
	}
	else if (buf[place] == ';')
	{
		buf[place] = 0;
		info->cmdBufferType = cmdChain;//define in h file
	}
	else
	{
		return (0);//return value here
	}
	*pointer = place;
	return (1);//return value here
}
/**
 * 
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t place = *pointer;

	if (info->cmdBufferType == cmdAnd)
	{
		if (info->status)
		{
			buf[i] = 0;
			place = len;
		}
	}
	if (info->cmdBufferType == cmdOr)
	{
		(!info->status)
		{
			buf[i] = 0;
			place = len;
		}
	}
	*pointer = place;
}
/**
 * 
 */
int replace_alias(info_t *info)//add to h file
{
	int count;
	list_t *node;
	char *pointer;
	
	for (count = 0;count < 10; count++)	
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (node == 0)
		{
			return (0);//return value here
		}
		free(info->arg[0]);
		pointer = _strchr(node->str, '=');
		if (pointer == 0)
		{
			return (0);
		}
		pointer = _strdup(p + 1);
		if (pointer == 0)
		{
			return (0);
		}
		info->argv[0] = pointer;
	}
	return (1);//return value here
}
/**
 * 
 */
int replace_vars(info_t *info)//add to h file
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
	return (0);//return value here
}

/**
 * 
 */
int replace_string(char **old, char *new)//add to h file
{
	free(*old);
	*old = new;
	return (1);//return value here
}
