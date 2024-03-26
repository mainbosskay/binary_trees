#include "binary_trees.h"

/**
 * binary_tree_delete - Deleting an entire binary tree
 * @tree: pointr to root node of the tree
 * Return: it is void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
