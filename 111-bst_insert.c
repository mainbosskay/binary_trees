#include "binary_trees.h"

/**
 * bst_insert - Inserting a value in a Binary Search Tree
 * @tree: double pointer to root node
 * @value: value to store in the node
 * Return: pointer to the created node, or NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nwnode = NULL, *parntnode = NULL;

	if (tree)
	{
		parntnode = *tree;
		if (!*tree)
		{
			nwnode = binary_tree_node(*tree, value);
			*tree = nwnode;
		}
		else
		{
			while (parntnode)
			{
				if ((parntnode->n > value) && (parntnode->left))
				{
					parntnode = parntnode->left;
				}
				else if ((parntnode->n < value) && (parntnode->right))
				{
					parntnode = parntnode->right;
				}
				else
					break;
			}
			if (parntnode->n < value)
			{
				nwnode = binary_tree_node(parntnode, value);
				parntnode->right = nwnode;
			}
			else if (parntnode->n > value)
			{
				nwnode = binary_tree_node(parntnode, value);
				parntnode->left = nwnode;
			}
		}
	}
	return (nwnode);
}
