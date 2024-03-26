#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserting node as left-child of another node
 * @parent: pointer to the node to inseert
 * @value: value to store the new node
 * Return: pointer to created node, or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nwnode = NULL;

	if (parent)
	{
		nwnode = malloc(sizeof(binary_tree_t));
		if (nwnode)
		{
			nwnode->left = parent->left;
			nwnode->right = NULL;
			nwnode->parent = parent;
			nwnode->n = value;
			if (parent->left)
			{
				parent->left->parent = nwnode;
			}
			parent->left = nwnode;
		}
	}
	return (nwnode);
}
