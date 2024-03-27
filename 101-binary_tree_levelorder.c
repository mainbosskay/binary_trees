#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * print_node_level - Printing binary tree nodes by level
 * @node: pointer to binary tree node
 * @func: pointer to function to call for each node
 * @treelvl: current binary tree level
 * Return: it is void
 */

void print_node_level(binary_tree_t *node, void (*func)(int), int treelvl)
{
	if (node && func)
	{
		if (treelvl == 1)
			func(node->n);
		if (treelvl > 1)
		{
			print_node_level(node->left, func, treelvl - 1);
			print_node_level(node->right, func, treelvl - 1);
		}
	}
}

/**
 * binary_tree_levelorder - Going through tree using level-order traversal
 * @tree: pointer to root node of the tree to traverse
 * @func: pointer to function to call for each node
 * Return: it is void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t treehgt;
	size_t currtlvl;
	binary_tree_t *treecpy;

	treehgt = 0;
	treecpy = (binary_tree_t *)tree;
	if (!tree || !func)
		return;
	treehgt = binary_tree_height(tree);
	for (currtlvl = 0 ; currtlvl <= treehgt + 1 ; currtlvl++)
		print_node_level(treecpy, func, currtlvl);
}
