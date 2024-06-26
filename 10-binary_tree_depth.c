#include "binary_trees.h"

/**
 * binary_tree_depth - Measuring depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (tree && tree->parent ? binary_tree_depth(tree->parent) + 1 : 0);
}
