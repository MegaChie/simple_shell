#include "shell.h"
/**
 * list_len - check code.
 * @h: constant struct pointer
 * Return: count value
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * list_to_strings - check code.
 * @head: struct pointer
 * Return: NULL or strs value
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t raw = list_len(head), collumn;
	char **strs;
	char *str;

	if (!head || !raw)
	{
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (raw + 1));
	if (!strs)
	{
		return (NULL);
	}
	for (raw = 0; node; node = node->next, raw++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (collumn = 0; collumn < raw; collumn++)
			{
				free(strs[collumn]);
			}
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[raw] = str;
	}
	strs[raw] = NULL;
	return (strs);
}


/**
 * print_list - check code.
 * @h: constant struct pointer
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * node_starts_with - check code.
 * @node: struct pointer
 * @prefix: char pointer
 * @c: char variable
 * Return: node value or NULL
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - check code
 * @head: struct pointer
 * @node: struct pointer
 * Return: count value or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t count = 0;

	while (head)
	{
		if (head == node)
			return (raw);
		head = head->next;
		count++;
	}
	return (-1);
}
