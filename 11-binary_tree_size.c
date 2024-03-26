#include "binary_trees.h"

/**
 * binary_tree_size - Measuring the size of a binary tree
 * @tree: pointer to root node of the tree to measure the size
 * Return: 0 if it is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t treesze = 0;

	if (tree)
	{
		treesze += 1;
		treesze += binary_tree_size(tree->left);
		treesze += binary_tree_size(tree->right);
	}
	return (treesze);
}
