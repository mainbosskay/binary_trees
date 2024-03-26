#include "binary_trees.h"

/**
 * binary_tree_node - Creating a binary tree node
 * @parent: parent node of the new binary tree
 * @value: value to put in the new node
 * Return: pointer to new node or NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nwnode = malloc(sizeof(binary_tree_t));

	if (nwnode)
	{
		nwnode->left = NULL;
		nwnode->right = NULL;
		nwnode->parent = parent;
		nwnode->n = value;
	}
	return (nwnode);
}
