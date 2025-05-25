#include "binary_trees.h"
/* malloc free */
#include <stdlib.h>


/**
 * BTQueuePush - adds member to rear of a bt_node_queue_t SLL
 *
 * @queue: pointer to head of bt_node_queue_t queue
 * @node: pointer to a node in a binary tree
 * Return: pointer to new node in queue, or NULL on failure
 */
bt_node_queue_t *BTQueuePush(bt_node_queue_t **queue, binary_tree_t *node)
{
	bt_node_queue_t *temp, *new = NULL;

	if (!queue || !node)
		return (NULL);

	new = malloc(sizeof(bt_node_queue_t));
	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;

	if (!*queue)
		*queue = new;
	else
	{
		temp = *queue;
		while (temp && temp->next)
			temp = temp->next;
		temp->next = new;
	}

	return (new);
}


/**
 * BTQueueAdvance - deletes first member of a bt_node_queue_t SLL
 *
 * @queue: pointer to head of bt_node_queue_t queue
 */
void BTQueueAdvance(bt_node_queue_t **queue)
{
	bt_node_queue_t *temp;

	if (!queue || !*queue)
		return;

	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
}


/**
 * lastInLevelOrder - uses queue to return last level order node in a complete
 *   binary tree
 *
 * @root: pointer to root node of tree to traverse
 * Return: pointer to the last node, or NULL on failure
 */
heap_t *lastInLevelOrder(heap_t *root)
{
	heap_t *last = NULL;
	bt_node_queue_t *queue = NULL;

	if (!root)
		return (NULL);
	/* normally would make check before handling that tree is complete */
	/* but project instructions don't allow for more than 5 funcs in file */

	queue = BTQueuePush(&queue, root);
	if (!queue)
		return (NULL);

	while (queue)
	{
		if ((queue->node->left &&
		     !BTQueuePush(&queue, queue->node->left)) ||
		    (queue->node->right &&
		     !BTQueuePush(&queue, queue->node->right)))
		{
			/* clear entire queue */
			while (queue)
				BTQueueAdvance(&queue);
			return (NULL);
		}

		/* level order last, assuming complete tree */
		if (!queue->next)
		{
			if (queue->node->left)
				last = queue->node->left;
			else
				last = queue->node;
		}

		BTQueueAdvance(&queue);
	}

	return (last);
}


/**
 * maxHeapSiftDown - Intended for use after swapping the data in the root and
 *   last level order nodes of a Binary Heap in preparation for extraction.
 *   Restores Max Binary Heap properties of a tree by sifting swapped data
 *   down from root position.
 *
 * @root: pointer to root node of a Max Binary Heap
 */
void maxHeapSiftDown(heap_t *root)
{
	heap_t *temp = NULL, *next = NULL;
	int swap;

	temp = root;
	while (temp && temp->left)
	{
		/* defaults to sifting down if parent == max child */
		/* and to left if left == right */
		if (!temp->right ||
		    temp->left->n - temp->right->n >= 0)
		{
			if (temp->n - temp->left->n <= 0)
				next = temp->left;
			else
				break;
		}
		else if (temp->n - temp->right->n <= 0)
			next = temp->right;
		else
			break;

		if (next)
		{
			swap = temp->n;
			temp->n = next->n;
			next->n = swap;
		}

		temp = next;
	}
}


/**
 * heap_extract - extacts the integer value at the root of a Max Binary Heap,
 *   expects heap to already be a complete binary tree
 *
 * @root: double pointer to root node of Max Binary Heap
 * Return: extracted integer, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last = NULL;
	int extract;

	if (root == NULL || *root == NULL)
		return (0);

	last = lastInLevelOrder(*root);
	if (!last)
		return (0);

	/* data from last node in level order copied into root node */
	extract = (*root)->n;
	(*root)->n = last->n;

	/* sift this copied data down to heapify back to Min Binary Heap */
	maxHeapSiftDown(*root);

	/* once swapped and re-heapified, delete last level order node */
	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else if (last->parent->right == last)
			last->parent->right = NULL;
	}

	if (last == *root)
		*root = NULL;
	free(last);

	return (extract);
}
