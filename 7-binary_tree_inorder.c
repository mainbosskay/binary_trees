#include "binary_trees.h"

/**
 * binary_tree_inorder - Going through binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call
 * Return: it is void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((tree) && (func))
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
