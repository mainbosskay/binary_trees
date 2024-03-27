#include "binary_trees.h"

/**
 * bst_search - Searching for a value in a Binary Search Tree
 * @tree: pointer to root node
 * @value: value to search in the tree
 * Return: pointer to node containing a value equals to value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tgnode;

	tgnode = NULL;
	if (tree)
	{
		if (tree->left)
		{
			tgnode = tree->left->parent;
		}
		if (!tgnode && tree->right)
		{
			tgnode = tree->right->parent;
		}
		while (tgnode)
		{
			if (tgnode->n < value)
			{
				tgnode = tgnode->right;
			}
			else if (tgnode->n > value)
			{
				tgnode = tgnode->left;
			}
			else
				break;
		}
	}
	return (tgnode);
}
