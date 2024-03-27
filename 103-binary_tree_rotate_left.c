#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performing a left-rotation on binary tree
 * @tree: pointer to root node
 * Return: pointer to new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rtori;
	binary_tree_t *rtnew;
	binary_tree_t *newrgtrt;

	if (!tree)
		return (NULL);
	rtori = tree;
	rtnew = rtori->right;
	if (rtnew)
	{
		rtnew->parent = rtori->parent;
		newrgtrt = rtnew->left;
		rtnew->left = rtori;
		if (rtori->parent)
		{
			if (rtori->parent->left == rtori)
				rtori->parent->left = rtnew;
			if (rtori->parent->right == rtori)
				rtori->parent->right = rtnew;
		}
		rtori->right = newrgtrt;
		rtori->parent = rtnew;
		if (newrgtrt)
		{
			newrgtrt->parent = rtori;
		}
	}
	return (rtnew);
}
