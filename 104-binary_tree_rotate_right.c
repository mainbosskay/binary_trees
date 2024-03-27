#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rtori;
	binary_tree_t *rtnew;
	binary_tree_t *newrgtrt;

	if (!tree)
		return (NULL);
	rtori = tree;
	rtnew = rtori->left;
	if (rtnew)
	{
		rtnew->parent = rtori->parent;
		newrgtrt = rtnew->right;
		rtnew->right = rtori;
		if (rtori->parent)
		{
			if (rtori->parent->left == rtori)
				rtori->parent->left = rtnew;
			if (rtori->parent->right == rtori)
				rtori->parent->right = rtnew;
		}
		rtori->left = newrgtrt;
		rtori->parent = rtnew;
		if (newrgtrt)
		{
			newrgtrt->parent = rtori;
		}
	}
	return (rtnew);
}
