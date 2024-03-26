#include "binary_trees.h"

/**
 * binary_tree_nodes - Counting the nodes with at least 1 child in binary tree
 * @tree: pointer to root node of the tree to count the number of nodes
 * Return: nodes with at least 1 child or 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t ndcnt;

	ndcnt = 0;
	if (tree)
	{
		ndcnt += (tree->left || tree->right);
		ndcnt += binary_tree_nodes(tree->left);
		ndcnt += binary_tree_nodes(tree->right);
	}
	return (ndcnt);
}
