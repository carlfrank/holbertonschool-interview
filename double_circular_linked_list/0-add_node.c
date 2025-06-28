#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Add a node at the end of a circular doubly linked list
 * @list: Double pointer to the head of the list
 * @str: String to duplicate and store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (!*list)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		List *tail = (*list)->prev;

		new_node->next = *list;
		new_node->prev = tail;
		tail->next = new_node;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Add a node at the beginning of a circular doubly linked list
 * @list: Double pointer to the head of the list
 * @str: String to duplicate and store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = add_node_end(list, str);
	if (new_node)
		*list = new_node;

	return (new_node);
}
