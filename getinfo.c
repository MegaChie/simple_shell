#include "shell.h"
/**
 * clear_info - check code.
 * @info: struct pointer
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - check code.
 * @info: struct pointer
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int count = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (count = 0; info->argv && info->argv[count]; count++)
		{

		}
		info->argc = count;
		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - check code.
 * @info: struct pointer
 * @all: integer variable
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
		{
			free(info->arg);
		}
		if (info->env)
		{
			free_list(&(info->env));
		}
		if (info->history)
		{
			free_list(&(info->history));
		}
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
		{
			close(info->readfd);
		}
		_putchar(BUF_FLUSH);
	}
}
