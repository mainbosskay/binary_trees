#include "binary_trees.h"

/**
 * binary_tree_leaves - Counting the leaves in a binary tree
 * @tree: pointer to root node of the tree to count the number of leaves
 * Return: number of leaves or 0
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lvscnt;

	lvscnt = 0;
	if (tree)
	{
		lvscnt += (!tree->left && !tree->right);
		lvscnt += binary_tree_leaves(tree->left);
		lvscnt += binary_tree_leaves(tree->right);
	}
	return (lvscnt);
}
