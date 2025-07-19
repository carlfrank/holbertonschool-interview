#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * is_bst_helper - Helper function to check if tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * @min: minimum value that nodes can have
 * @max: maximum value that nodes can have
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
			is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? (int)binary_tree_height(tree->left) + 1 : 0;
	right_height = tree->right ? (int)binary_tree_height(tree->right) + 1 : 0;

	return (left_height - right_height);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);

	/* Check if it's a valid BST */
	if (!binary_tree_is_bst(tree))
		return (0);

	/* Check balance factor */
	balance = binary_tree_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);

	/* Recursively check left and right subtrees */
	if (tree->left && !binary_tree_is_avl(tree->left))
		return (0);
	if (tree->right && !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
