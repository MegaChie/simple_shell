#include "Shell.h"
/**
 * 
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);//return value here
}

/**
 * 
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t count = list_len(head), place;
	char **strs;
	char *str;

	if (!head || !count)
	{
		return (0);//return value here
	}
	strs = malloc(sizeof(char *) * (count + 1));
	if (strs == 0)
	{
		return (0);
	}
	for (count = 0; node; node = node->next; count++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (str == 0)
		{
			for (place = 0; place < count; place++)
			{
				free(strs[place]);
			}
			free(strs);
			return (0);
		}
		str = _strcpy(str, node->str);
		strs[count] = str;
	}
	strs[count] = NULL;
	return (strs);//return value here
}

/**
 * 
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->srt : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);//retuen value here
}
/**
 * 
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *pointer = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (pointer && ((c == -1) || (*pointer == c)))
		{
			return (node);//return value here
		}
		node = node->next;
	}
	return (0);//return value here
}

/**
 * 
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t count = 0;

	while (head)
	{
		if (head == node)
		{
			return (count);//return value here
		}
		head = head->next;
		count++;
	}
	return (-1);//return value here
}
