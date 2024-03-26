#include "binary_trees.h"

/**
 * binary_tree_stats - Calculating the statistics of binary tree
 * @tree: pointer to the binary tree to be calculated
 * @pathlen: total height of the current path in binary tree
 * @lvsval: pointer to binary tree's leaf count value
 * @max_ht: pointer to binary tree's maximum height value
 * Return: it is void
 */

void binary_tree_stats(const binary_tree_t *tree, size_t pathlen,
		size_t *lvsval, size_t *max_ht)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
		{
			if (lvsval)
			{
				(*lvsval)++;
			}
			if (max_ht && (pathlen > *max_ht))
			{
				*max_ht = pathlen;
			}
		}
		else
		{
			binary_tree_stats(tree->left, pathlen + 1, lvsval, max_ht);
			binary_tree_stats(tree->right, pathlen + 1, lvsval, max_ht);
		}
	}
}

/**
 * binary_tree_is_perfect - Checking if binary tree is perfect
 * @tree: pointer to root node of the tree to check
 * Return: 0 if it is NULL or 1 if it is perfect
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t lvscnt;
	size_t treehgt;

	lvscnt = 0;
	treehgt = 0;
	binary_tree_stats(tree, 0, &lvscnt, &treehgt);
	return ((int)lvscnt == (1 << treehgt));
}
