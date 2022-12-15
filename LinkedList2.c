#include "Shell.h"
/**
 * list_len - check code
 * @h: list pointer
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
 * @head: list variable
 * Rerurn: 0 or strs value
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t count = list_len(head), place;
	char **strs;
	char *str;

	if (!head || !count)
	{
		return (0);
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
	return (strs);
}

/**
 * print_list - check code.
 * @h: list variable
 * Return: count value
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
	return (count);
}
/**
 * node_starts_with - check code.
 * @node: list variable
 * @prefix: char pointer
 * @c: char variable
 * Return: node value or 0
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *pointer = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (pointer && ((c == -1) || (*pointer == c)))
		{
			return (node);
		}
		node = node->next;
	}
	return (0);
}

/**
 * get_node_index - check code.
 * @head: list variable
 * @node: list variable
 * Return: count value or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t count = 0;

	while (head)
	{
		if (head == node)
		{
			return (count);
		}
		head = head->next;
		count++;
	}
	return (-1);
}
