#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
 * tree_comp - Checking if a tree is complete
 * @tree: pointer to root of the tree to be checked
 * @ndindx: index for right and left node
 * @treesze: size of tree to be checked
 * Return: 1 if tree is complete or 0
 */

int tree_comp(const binary_tree_t *tree, int ndindx, int treesze)
{
	if (!tree)
	{
		return (1);
	}
	if (ndindx >= treesze)
	{
		return (0);
	}
	return (tree_comp(tree->left, 2 * ndindx + 1, treesze) &&
			tree_comp(tree->right, 2 * ndindx + 2, treesze));
}

/**
 * binary_tree_is_complete - Checking if a binary tree is complete
 * @tree: pointer to root node of tree to check
 * Return: 0 if it is NULL, otherwise 1
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int treesze;
	int ndindx;

	treesze = binary_tree_size(tree);
	ndindx = 0;
	if (!tree)
	{
		return (0);
	}
	return (tree_comp(tree, ndindx, treesze));
}
