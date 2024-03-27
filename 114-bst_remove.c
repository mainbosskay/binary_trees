#include "binary_trees.h"

/**
 * bst_inorder_successor - Finding the minimum value of a Binary Search Tree
 * @root: pointer to root node
 * Return: pointer to the node with the minimum value
 */

bst_t *bst_inorder_successor(bst_t *root)
{
	while (root->left)
	{
		root = root->left;
	}
	return (root);
}

/**
 * bst_delete_node - Deleting a given node from a BST
 * @root: pointer to root node
 * @tgnode: pointer to target node to delete
 * Return: pointer to the new root node after deletion
 */

bst_t *bst_delete_node(bst_t *root, bst_t *tgnode)
{
	bst_t *parntnode = tgnode->parent;
	bst_t *posnd = NULL;

	if (!tgnode->left)
	{
		if (parntnode && parntnode->left == tgnode)
		{
			parntnode->left = tgnode->right;
		}
		else if (parntnode)
		{
			parntnode->right = tgnode->right;
		}
		if (tgnode->right)
		{
			tgnode->right->parent = parntnode;
		}
		free(tgnode);
		return (!parntnode ? tgnode->right : root);
	}
	if (!tgnode->right)
	{
		if (parntnode && parntnode->left == tgnode)
		{
			parntnode->left = tgnode->left;
		}
		else if (parntnode)
		{
			parntnode->right = tgnode->left;
		}
		if (tgnode->left)
		{
			tgnode->left->parent = parntnode;
		}
		free(tgnode);
		return (!parntnode ? tgnode->left : root);
	}
	posnd = bst_inorder_successor(tgnode->right);
	tgnode->n = posnd->n;
	return (bst_delete_node(root, posnd));
}

/**
 * bst_remove_node_iter - Iteratively remove a node from a Binary Search Tree
 * @root: pointer to root node
 * @currtnd: pointer to the current node in the Binary Search Tree
 * @value: value to remove from the Binary Search Tree
 * Return: pointer to the new root node after removal
 */

bst_t *bst_remove_node_iter(bst_t *root, bst_t *currtnd, int value)
{
	if (currtnd)
	{
		if (currtnd->n == value)
		{
			return (bst_delete_node(root, currtnd));
		}
		if (currtnd->n > value)
		{
			return (bst_remove_node_iter(root, currtnd->left, value));
		}
		return (bst_remove_node_iter(root, currtnd->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removing a node from a Binary Search Tree
 * @root: pointer to root node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of tree after removal
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_node_iter(root, root, value));
}
