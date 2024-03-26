#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checking if node is a leaf
 * @node: pointer to the node
 * Return: 1 if the node is a leaf, otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	int leafnode;

	leafnode = 0;
	if (node)
	{
		leafnode = (node->left == NULL && node->right == NULL);
	}
	return (leafnode);
}
