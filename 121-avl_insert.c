#include "binary_trees.h"

/**
 * bst_insert_node - Adding a node to a Binary Search Tree
 * @tree: double pointer to Binary Search Tree
 * @value: value to be added to the new node
 * Return: pointer to new node or NULL
 */

bst_t *bst_insert_node(bst_t **tree, int value)
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
				if (parntnode->n > value && parntnode->left)
					parntnode = parntnode->left;
				else if (parntnode->n < value && parntnode->right)
					parntnode = parntnode->right;
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

/**
 * bt_height - Calculating the height of a binary tree
 * @tree: pointer to binary tree
 * Return: height of binary tree
 */

int bt_height(const binary_tree_t *tree)
{
	int lthgt;
	int rthgt;

	lthgt = 0;
	rthgt = 0;
	if (tree)
	{
		lthgt = bt_height(tree->left);
		rthgt = bt_height(tree->right);
	}
	return ((lthgt > rthgt ? lthgt : rthgt) + 1);
}

/**
 * avl_balance - Rebalancing an AVL tree
 * @tree: double pointer to root node
 * @instnd: pointer to newly inserted node
 * Return: it is void
 */

void avl_balance(avl_t **tree, avl_t *instnd)
{
	avl_t *currtnd = instnd, *nwtree = *tree;
	int lthgt = 0, rthgt = 0, balfval = 0;

	while (currtnd)
	{
		lthgt = bt_height(currtnd->left);
		rthgt = bt_height(currtnd->right);
		balfval = lthgt - rthgt;
		if (!((balfval >= -1) && (balfval <= 1)))
		{
			if ((balfval == 2) && (instnd->n < currtnd->left->n))
			{
				nwtree = binary_tree_rotate_right(currtnd);
			}
			else if ((balfval == 2) && (instnd->n > currtnd->left->n))
			{
				currtnd->left = binary_tree_rotate_left(currtnd->left);
				nwtree = binary_tree_rotate_right(currtnd);
			}
			else if ((balfval == -2) && (instnd->n > currtnd->right->n))
			{
				nwtree = binary_tree_rotate_left(currtnd);
			}
			else if ((balfval == -2) && (instnd->n < currtnd->right->n))
			{
				currtnd->right = binary_tree_rotate_right(currtnd->right);
				nwtree = binary_tree_rotate_left(currtnd);
			}
			nwtree = (currtnd == *tree ? nwtree : *tree);
			break;
		}
		currtnd = currtnd->parent;
	}
	*tree = nwtree;
}

/**
 * avl_insert - Inserting a value in an AVL Tree
 * @tree: double pointer to root node of the AVL tree
 * @value: value to store in the node
 * Return: pointer to created node, or NULL
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *nwnode;

	nwnode = NULL;
	if (tree)
	{
		nwnode = bst_insert_node(tree, value);
		avl_balance(tree, nwnode);
	}
	return (nwnode);
}
