#include "binary_trees.h"

/**
 * binary_tree_uncle - Finding the uncle of a node
 * @node: pointer to node to find the uncle
 * Return: pointer to uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *ltnode;
	binary_tree_t *rtnode;
	binary_tree_t *partnode;

	ltnode = NULL;
	rtnode = NULL;
	partnode = (node ? node->parent : NULL);
	if (partnode && partnode->parent)
	{
		ltnode = partnode->parent->left;
		rtnode = partnode->parent->right;
	}
	return (ltnode == partnode ? rtnode : ltnode);
}
