#include "binary_trees.h"

/**
 * binary_bst_check - Checking if binary tree is a Binary Search Tree
 * @tree: pointer to the binary tree
 * @minval: minimum value allowed
 * @maxval: maximum value allowed
 * @valdbst: pointer to validation flag value of the tree
 * Return: it is void
 */

void binary_bst_check(const binary_tree_t *tree, int minval, int maxval,
		int *valdbst)
{
	if (tree)
	{
		if ((tree->n > minval) && (tree->n < maxval))
		{
			binary_bst_check(tree->left, minval, tree->n, valdbst);
			binary_bst_check(tree->right, tree->n, maxval, valdbst);
		}
		else
		{
			if (valdbst)
			{
				*valdbst = 0;
			}
		}
	}
}

/**
 * bt_height - Calculating the height of a binary tree
 * @tree: pointer to the binary tree
 * @currtht: the current height of the binary tree
 * @max_ht: pointer to maximum height of binary tree
 * Return: it is void
 */

void bt_height(const binary_tree_t *tree, int currtht, int *max_ht)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
		{
			if (currtht > *max_ht)
			{
				*max_ht = currtht;
			}
		}
		else
		{
			bt_height(tree->left, currtht + 1, max_ht);
			bt_height(tree->right, currtht + 1, max_ht);
		}
	}
}

/**
 * bt_balance - Checking the balance of a binary tree
 * @tree: pointer to binary tree
 * @valdbal: pointer to balanced tree flag value
 * Return: it is void
 */

void bt_balance(const binary_tree_t *tree, int *valdbal)
{
	int balfval;
	int lthgt;
	int rthgt;

	balfval = 0;
	lthgt = 0;
	rthgt = 0;
	if (tree)
	{
		bt_height(tree->left, 1, &lthgt);
		bt_height(tree->right, 1, &rthgt);
		balfval = lthgt - rthgt;
		if (balfval < -1 || balfval > 1)
		{
			if (valdbal)
			{
				*valdbal = 0;
			}
		}
		else
		{
			bt_balance(tree->left, valdbal);
			bt_balance(tree->right, valdbal);
		}
	}
}

/**
 * binary_tree_is_avl - Checking if a binary tree is a valid AVL Tree
 * @tree: pointer to root node
 * Return: 1 if it is a valid AVL Tree, or 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int valdbst;
	int valdavl;

	valdbst = 0;
	valdavl = 0;
	if (tree)
	{
		valdbst = 1;
		binary_bst_check(tree, INT_MIN, INT_MAX, &valdbst);
		if (valdbst == 1)
		{
			valdavl = 1;
			bt_balance(tree, &valdavl);
		}
	}
	return (valdavl);
}
