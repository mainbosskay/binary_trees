#include "binary_trees.h"

/**
 * binary_tree_sibling - Finding the sibling of a node
 * @node: pointer to node to find the sibling
 * Return: pointer to sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *ltnode;
	binary_tree_t *rtnode;

	ltnode = NULL;
	rtnode = NULL;
	if (node && node->parent)
	{
		ltnode = node->parent->left;
		rtnode = node->parent->right;
	}
	return (ltnode == node ? rtnode : ltnode);
}
