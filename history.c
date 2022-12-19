#include "shell.h"
/**
 * get_history_file - check code.
 * @info: struct pointer
 * Return: NULL or buffer value
 */

char *get_history_file(info_t *info)
{
	char *buffer, *dire;

	dire = _getenv(info, "HOME=");
	if (!dire)
	{
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (_strlen(dire) + _strlen(HIST_FILE) + 2));
	if (!buffer)
	{
		return (NULL);
	}
	buffer[0] = 0;
	_strcpy(buffer, dire);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE);
	return (buffer);
}

/**
 * write_history - check code.
 * @info: struct pointer
 * Return: -1 or 1
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *fileName = get_history_file(info);
	list_t *node = NULL;

	if (!fileName)
	{
		return (-1);
	}
	fd = open(fileName, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fileName);
	if (fd == -1)
	{
		return (-1);
	}
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - check code.
 * @info: struct pointer
 * Return: 0 or functions values
 */
int read_history(info_t *info)
{
	int count, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buffer = NULL, *fileName = get_history_file(info);

	if (!fileName)
	{
		return (0);
	}
	fd = open(fileName, O_RDONLY);
	free(fileName);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
		return (0);
	rdlen = read(fd, buffer, fsize);
	buffer[fsize] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fd);
	for (count = 0; count < fsize; count++)
		if (buffer[count] == '\n')
		{
			buffer[count] = 0;
			build_history_list(info, buffer + last, linecount++);
			last = count + 1;
		}
	if (last != count)
		build_history_list(info, buffer + last, linecount++);
	free(buffer);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - check code.
 * @info: struct pointer
 * @buffer: char pointer
 * @linecount: integer value
 * Return: 0
 */
int build_history_list(info_t *info, char *buffer, int linecount)
{
	list_t *node = NULL;

	if (info->history)
	{
		node = info->history;
	}
	add_node_end(&node, buffer, linecount);
	if (!info->history)
	{
		info->history = node;
	}
	return (0);
}

/**
 * renumber_history - check code.
 * @info: Struct pointer
 * Return: function value
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int count = 0;

	while (node)
	{
		node->num = count++;
		node = node->next;
	}
	return (info->histcount = count);
}
