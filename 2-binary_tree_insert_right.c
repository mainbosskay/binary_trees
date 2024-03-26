#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserting node as right-child of another node
 * @parent: pointer to the node to insert
 * @value: value to store in new node
 * Return: pointer to the create node, or NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nwnode = NULL;

	if (parent)
	{
		nwnode = malloc(sizeof(binary_tree_t));
		if (nwnode)
		{
			nwnode->left = NULL;
			nwnode->right = parent->right;
			nwnode->parent = parent;
			nwnode->n = value;
			if (parent->right)
			{
				parent->right->parent = nwnode;
			}
			parent->right = nwnode;
		}
	}
	return (nwnode);
}
