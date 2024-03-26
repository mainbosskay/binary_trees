#include "binary_trees.h"

/**
 * binary_tree_height - Measuring the height of binary tree
 * @tree: pointer to the root node of the tree to measure height
 * Return: height or 0 if it is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lthgt;
		size_t rthgt;

		lthgt = 0;
		rthgt = 0;
		lthgt = (tree->left) ? binary_tree_height(tree->left) + 1 : 0;
		rthgt = (tree->right) ? binary_tree_height(tree->right) + 1 : 0;
		return (lthgt > rthgt ? lthgt : rthgt);
	}
	return (0);
}
