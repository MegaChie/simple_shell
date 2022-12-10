#include "Shell.h"
/**
 * 
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *newHead;

	if (head == 0)
	{
		return (0);
	}
	newHead = malloc(sizeof(list_t));
	if (newHead == 0)
	{
		return (0);
	}
	_memset((void *)newHead, 0, sizeof(list_t));
	newHead->num = num;
	if (str)
	{
		newHead->str = _strdup(str);
		if (newHead->str == 0)
		{
			free(newHead);
			return (0);//return value here
		}
	}
	newHead->next = *head;
	*head = newHead;
	return (newHead);//return value here
}

/**
 * 
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *newNode, *node;

	if (head == 0)
	{
		return (0);//return value here
	}
	node = *head;
	newNode = malloc(sizeof(list_t));
	if (newNode == 0)
	{
		return (0);
	}
	_memset((void *)newNode, 0, sizeof(list_t));
	newNode->num = num;
	if (str)
	{
		newNode->str = _strdup(str);
		if (newNode->str == 0)
		{
			free(newNode);
			return (0);
		}
	}
	if (node)
	{
		while (node->next)
		{
			node = node->next;
		}
		node->next = newNode
	}
	else
	{
		*head = newNode;
	}
	return (newNode);
}
/**
 * 
 */
size_t print_list_str(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		_puts(h->srt ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		count++;
	}
	return (count);//return valur here
}

/**
 * 
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *previousNode;
	unsigned int count = 0;

	if (!head || !*head)
	{
		return (0);//return value here
	}
	if (index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);//return value here
	}
	node = *head;
	while (node)
	{
		if (count == index)
		{
			previousNode->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		count++;
		previousNode = node;
		node = node->next;
	}
	return (0);
}

/**
 * 
 */
void free_list(list_t **headPointer)
{
	list_t *node, *nextNode, *head;

	if (!headPointer || !*headPointer)
	{
		return;
	}
	head = *headPointer;
	node = head;
	while (node)
	{
		nextNode = node->next;
		free(node->str);
		free(node);
		node = nextNode;
	}
	*headPointer = NULL;
}
