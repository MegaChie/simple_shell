#include "shell.h"

/**
 * is_cmd - check code.
 * @info: struct pointer
 * @path: char pointer
 * Return: 0 or 1
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	{
		return (0);
	}
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - check code.
 * @pathstr: char pointer
 * @start: integer variable
 * @stop: integer variable
 * Return: buffer value
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int raw = 0, collumn = 0;

	for (collumn = 0, raw = start; raw < stop; raw++)
	{
		if (pathstr[raw] != ':')
		{
			buf[collumn++] = pathstr[raw];
		}
	}
	buf[collumn] = 0;
	return (buf);
}

/**
 * find_path - check code.
 * @info: struct pointer
 * @pathstr: char pointer
 * @cmd: char pointer
 * Return: cmd value or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int count = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
	{
		return (NULL);
	}
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
		{
			return (cmd);
		}
	}
	while (1)
	{
		if (!pathstr[count] || pathstr[count] == ':')
		{
			path = dup_chars(pathstr, curr_pos, count);
			if (!*path)
			{
				_strcat(path, cmd);
			}
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
			{
				return (path);
			}
			if (!pathstr[count])
			break;
			curr_pos = count;
		}
		count++;
	}
	return (NULL);
}
