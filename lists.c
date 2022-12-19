#include "shell.h"
/**
 * add_node - check code.
 * @head: struct double pointer
 * @str: constant char pointer
 * @num: integer variable
 * Return: NULL or newHead value
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *newHead;

	if (!head)
	{
		return (NULL);
	}
	newHead = malloc(sizeof(list_t));
	if (!newHead)
	{
		return (NULL);
	}
	_memset((void *)newHead, 0, sizeof(list_t));
	newHead->num = num;
	if (str)
	{
		newHead->str = _strdup(str);
		if (!newHead->str)
		{
			free(newHead);
			return (NULL);
		}
	}
	newHead->next = *head;
	*head = newHead;
	return (newHead);
}

/**
 * add_node_end - check code.
 * @head: struct double pointer
 * @str: constant char pointer
 * @num: integer variable
 * Return: NULL Or newNode value
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *newNode, *node;

	if (!head)
	{
		return (NULL);
	}
	node = *head;
	newNode = malloc(sizeof(list_t));
	if (!newNode)
	{
		return (NULL);
	}
	_memset((void *)newNode, 0, sizeof(list_t));
	newNode->num = num;
	if (str)
	{
		newNode->str = _strdup(str);
		if (!newNode->str)
		{
			free(newNode);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = newNode;
	}
	else
	{
		*head = newNode;
	}
	return (newNode);
}

/**
 * print_list_str - check code.
 * @h: constant struct pointer
 * Return: count value
 */
size_t print_list_str(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);
}

/**
 * delete_node_at_index - check code.
 * @head: struct double pointer
 * @index: unsigned integer variable
 * Return: 0 or 1
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int count = 0;

	if (!head || !*head)
	{
		return (0);
	}
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (count == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		count++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - check code.
 * @head_ptr: struct double pointer
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *nextNode, *head;

	if (!head_ptr || !*head_ptr)
	{
		return;
	}
	head = *head_ptr;
	node = head;
	while (node)
	{
		nextNode = node->next;
		free(node->str);
		free(node);
		node = nextNode;
	}
	*head_ptr = NULL;
}
