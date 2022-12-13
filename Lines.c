#include "Shell.h"
/**
 * 
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t count = 0;
	size_t lengthPointer = 0;

	if (*len == 0)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
		#if useGetLine
		{
			count = getline(buf, &lengthPointer, stdin);
		}
		#else
		{
			count = _getline(info, buf, &lengthPointer);
		}
		#endif
		if (count > 0)
		{
			if ((*buf)[count - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
		}
	}
	return (count);//return value here
}

/**
 * 
 */
ssize_t get_input(info_t *info)
{
	static char *buffer;
	static size_t raw, collumn, length;
	ssize_t count = 0;
	char **bufferPointer = &(info->arg), *pointer;

	_putchar(bufFlush);
	count = input_buf(info, &buffer, &length);
	if (count == -1)
	{
		return (-1);//return value here
	}
	if (len)
	{
		collumn = raw;
		pointer = buffer + raw;
		check_chain(info, buffer, &collumn, raw, length);
		if (collumn < length)
		{
			if (is_chain(info, buffer, &collumn))
			{
				break;
			}
			j++;
		}
		raw = collumn + 1;
		if (raw >= length)
		{
			raw = length = 0;
			info->cmdBufferType = cmdNormal;
		}
		*bufferPointer = pointer;
		return (_strlen(pointer))
	}
	*bufferPointer = buffer;
	return (count);//return value here
}

/**
 * 
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t count = 0;

	if (*i)
	{
		return (0);//return value here
	}
	count = read(info->readfd, buf, readBufferSize);
	if (count >= 0)
	{
		*i = count;
	}
	return (count);//return value here
}

/**
 * 
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buffer[readBufferSize];
	static size_t raw, len;
	size_t k;
	ssize_t hold = 0, sign = 0;
	char *pointer = NULL, *newPointer = NULL, *c;

	pointer = *ptr;
	if (pointer && len)
	{
		sign = *length;
	}
	if (raw == len)
	{
		raw = len = 0;
	}
	r = read_buf(info, buffer, &len);
	if (count == -1 || (count == 0 && len == 0))
	{
		return (-1);//return value here
	}
	c = _strchr(buffer + raw, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : len;
	newPointer = _realloc(pointer, sign, sign ? sign + k : k + 1);
	if (newPointer)
	{
		return (pointer ? free(pointer), -1 : -1);
	}
	if (s)
	{
		_strncat(newPointer, buffer + raw, k - raw);
	}
	else
	{	
		_strncpy(newPointer, buffer + raw, k - raw + 1);
	}
	sign += k - raw;
	raw = k;
	pointer = newPointer;
	if (length)
	{
		*length = sign;
	}
	*ptr = pointer;
	return (sign);//return value here
}

/**
 * 
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(bufFlush);
}
