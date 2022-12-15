#include "Shell.h"
/**
 * hsh - check code.
 * @info; list variable
 * @av: char double pointer
 * Return: buildReturn value
 */
int hsh(info_t *info, char **av)
{
	ssize_t count = 0;
	int buildReturn = 0;

	while (count != -1 && buildReturn != -2)
	{
		clear_info(info);
		if (interactive(info))
		{
			_puts("$ ");
		}
		_eputchar(bufFlush);
		count = get_input(info);
		if (count != -1)
		{
			set_info(info, av);
			buildReturn = find_builtin(info);
			if (buildReturn == -1)
			{
				find_cmd(info);
			}
		}
		else if (interactive(info))
		{
			_putchar('\n');
		}
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
	{
		exit(info->status);
	}
	if (buildReturn == -2)
	{
		if (info->err_num == -1)
		{
			exit(info->status);
		}
		exit(info->err_num);
	}
	return (buildReturn);
}

/**
 * find_builtin - check code.
 * @info: list variable
 * Return: builtInReturn value
 */
int find_builtin(info_t *info)
{
	int raw, builtInReturn = -1;
	buildTable tableBuild1[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (raw = 0; tableBuild1[raw].type; raw++ )
	{
		if (_strcmp(info->argv[0], tableBuild1[raw].type) == 0)
		{
			info->line_count++;
			builtInReturn = tableBuild1[raw].func(info);
			break;
		}
	}
	return (builtInReturn);
}
/**
 * find_cmd - check code.
 * @info: list variable
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int raw, place;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	if (raw = 0, place = 0; info->arg[raw]; raw++)
	{
		if (!is_delim(info->arg[raw], " \t\n"))
		{
			place++;
		}
	}
	if (place == 0)
	{
		return;
	}
	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
		{
			fork_cmd(info);
		}
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - check code.
 * @info: list variable
 */
void fork_cmd(info_t *info)
{
	pid_t childPId;

	childPId = fork();
	if (childPId == -1)
	{
		perror("Error:");
		return;	
	}
	if (childPId == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
			{
				exit(126);
			}
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
			{
				print_error(info, "Permission denied\n");
			}
		}
	}
}
