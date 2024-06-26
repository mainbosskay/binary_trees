#include "binary_trees.h"

/**
 * binary_tree_is_root - Checking if given node is a root
 * @node: pointer to the node
 * Return: 1 if the node is a root, otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if ((node) && (!node->parent))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
