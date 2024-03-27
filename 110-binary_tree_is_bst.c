#include "binary_trees.h"

/**
 * binary_tree_value - Checking the allowable values of a binary tree
 * @node: pointer to node of binary tree
 * @minval: minimum allowable value
 * @maxval: maximum allowable value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_value(const binary_tree_t *node, int minval, int maxval)
{
	if (!node)
		return (1);
	if (node->n < minval || node->n > maxval)
	{
		return (0);
	}
	return (binary_tree_value(node->left, minval, node->n - 1) &&
			binary_tree_value(node->right, node->n + 1, maxval));
}

/**
 * binary_tree_is_bst - Checking if binary tree is valid Binary Search Tree
 * @tree: pointer to root node
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (binary_tree_value(tree, INT_MIN, INT_MAX));
}
