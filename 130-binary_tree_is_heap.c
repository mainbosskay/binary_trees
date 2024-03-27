#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * bt_maxvalue - Checking each node of binary tree is maximum value
 * @root: pointer to root node
 * Return: 1 if all nodes are at maximum value or 0 otherwise
 */

int bt_maxvalue(const binary_tree_t *root)
{
	int ltnd;
	int rtnd;

	ltnd = 1;
	rtnd = 1;
	if (!root)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->left)
	{
		if (root->n <= root->left->n)
			return (0);
		ltnd = bt_maxvalue(root->left);
	}
	if (root->right)
	{
		if (root->n <= root->right->n)
			return (0);
		rtnd = bt_maxvalue(root->right);
	}
	return (ltnd && rtnd);
}

/**
 * binary_tree_is_heap - Checking if binary tree is valid Max Binary Heap
 * @tree: pointer to root node
 * Return: 1 if it is a valid Max Binary Heap, and 0
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int compress;

	if (!tree)
		return (0);
	compress = binary_tree_is_complete(tree);
	if (!compress)
		return (0);
	return (bt_maxvalue(tree));
}
