#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s heap_t;

/* 0-heap_extract.c */
/**
 * struct bt_node_queue_s - node in singly linked list used as a
 *   queue to traverse a binary tree in level order
 *
 * @node: pointer to node in a binary tree
 * @next: pointer to next member of queue
 */
typedef struct bt_node_queue_s
{
	heap_t *node;
	struct bt_node_queue_s *next;
} bt_node_queue_t;

/* 0-heap_extract.c */
bt_node_queue_t *BTQueuePush(bt_node_queue_t **queue, binary_tree_t *node);
void BTQueueAdvance(bt_node_queue_t **queue);
heap_t *lastInLevelOrder(heap_t *root);
void maxHeapSiftDown(heap_t *root);
int heap_extract(heap_t **root);


#endif /* BINARY_TREES_H */