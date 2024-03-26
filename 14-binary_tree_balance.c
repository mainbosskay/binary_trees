#include "binary_trees.h"

/**
 * binary_tree_balance - Measuring the balance factor of binary tree
 * @tree: pointer to root node of the tree to measure the balance factor
 * Return: tree balance factor or 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - Measuring the height of binary tree
 * @tree: pointer to root node of the tree to measure the height
 * Return: height or 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lthgt;
		size_t rthgt;

		lthgt = 0;
		rthgt = 0;
		lthgt = (tree->left) ? binary_tree_height(tree->left) + 1 : 1;
		rthgt = (tree->right) ? binary_tree_height(tree->right) + 1 : 1;
		return (lthgt > rthgt ? lthgt : rthgt);
	}
	return (0);
}
