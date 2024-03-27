#include "binary_trees.h"

/**
 * avl_balfval - Calculating the balance factor of a AVL tree
 * @tree: double pointer to tree to calculate
 * Return: it is void
 */

void avl_balfval(avl_t **tree)
{
	int balval;

	if (!tree || !*tree)
		return;
	if (!(*tree)->left && !(*tree)->right)
		return;
	avl_balfval(&(*tree)->left);
	avl_balfval(&(*tree)->right);
	balval = binary_tree_balance((const binary_tree_t *)*tree);
	if (balval > 1)
	{
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	}
	else if (balval < -1)
	{
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
	}
}

/**
 * inorder_successor - Finding minimum value of a Binary Search Tree
 * @root: pointer to root node
 * Return: node with minimum value
 */

int inorder_successor(bst_t *root)
{
	int ltmin;

	ltmin = 0;
	if (!root)
	{
		return (0);
	}
	else
	{
		ltmin = inorder_successor(root->left);
		if (ltmin == 0)
		{
			return (root->n);
		}
		return (ltmin);
	}
}

/**
 * remove_node_type - Deleting a node based on its children
 * @node: pointer to node to be removed
 * Return: new value of the node or 0
 */

int remove_node_type(bst_t *node)
{
	int nwval = 0;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
	{
		nwval = inorder_successor(node->right);
		node->n = nwval;
		return (nwval);
	}
}

/**
 * bst_remove_node - Removing a node from a Binary Search Tree
 * @root: pointer to root node
 * @value: value to remove in the tree
 * Return: pointer to new root node of tree after removal
 */

bst_t *bst_remove_node(bst_t *root, int value)
{
	int ndtype = 0;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove_node(root->left, value);
	else if (value > root->n)
		bst_remove_node(root->right, value);
	else if (value == root->n)
	{
		ndtype = remove_node_type(root);
		if (ndtype != 0)
			bst_remove_node(root->right, ndtype);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removing a node from an AVL tree
 * @root: pointer to root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to new root node of tree after removal
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *rtaft;

	rtaft = (avl_t *) bst_remove_node((bst_t *) root, value);
	if (!rtaft)
		return (NULL);
	avl_balfval(&rtaft);
	return (rtaft);
}
