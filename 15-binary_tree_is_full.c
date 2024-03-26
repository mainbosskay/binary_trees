#include "binary_trees.h"

/**
 * binary_tree_is_full - Checing if binary tree is full
 * @tree: pointer to root node of the tree to check
 * Return: 0 if it is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int rtcnt;
	int ltcnt;

	rtcnt = 0;
	ltcnt = 0;
	if (!tree || !tree->left != !tree->right)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	ltcnt = binary_tree_is_full(tree->left);
	rtcnt = binary_tree_is_full(tree->right);
	if (rtcnt && ltcnt)
		return (1);
	return (0);
}
