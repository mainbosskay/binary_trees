#include "binary_trees.h"

/**
 * bt_height - Calculating the height of a binary tree
 * @root: pointer to root node
 * Return: binary tree height or 0
 */

size_t bt_height(const heap_t *root)
{
	size_t lthgt;
	size_t rthgt;

	lthgt = 0;
	rthgt = 0;
	if (!root)
		return (0);
	if (root->left)
		lthgt = 1 + bt_height(root->left);
	if (root->right)
		rthgt = 1 + bt_height(root->right);
	if (lthgt > rthgt)
		return (lthgt);
	return (rthgt);
}

/**
 * bt_height_sum - Calculating the sum of heights of a binary tree
 * @root: pointer to root node
 * Return: sum of binary tree heights or 0
 */

size_t bt_height_sum(const binary_tree_t *root)
{
	size_t lthgt;
	size_t rthgt;

	lthgt = 0;
	rthgt = 0;
	if (!root)
		return (0);
	if (root->left)
		lthgt = 1 + bt_height_sum(root->left);
	if (root->right)
		rthgt = 1 + bt_height_sum(root->right);
	return (lthgt + rthgt);
}

/**
 * trav_preorder - Navigating through  binary tree using pre-order traversal
 * @strtnd: pointer to starting node of binary tree to navigate
 * @lstnd: double pointer to ending node in traversal
 * @treehgt: total height of binary tree
 * Return: it is void
 */

void trav_preorder(heap_t *strtnd, heap_t **lstnd, size_t treehgt)
{
	if (!strtnd)
		return;
	if (!treehgt)
		*lstnd = strtnd;
	treehgt--;
	trav_preorder(strtnd->left, lstnd, treehgt);
	trav_preorder(strtnd->right, lstnd, treehgt);
}

/**
 * trans_max_heap - Changing a binary heap into a max heap
 * @root: pointer to root of binary heap
 * Return: it is void
 */

void trans_max_heap(heap_t *root)
{
	int exhval;
	heap_t *currtnd;
	heap_t *selnd;

	if (!root)
		return;
	currtnd = root;
	while (1)
	{
		if (!currtnd->left)
			break;
		if (!currtnd->right)
			selnd = currtnd->left;
		else
		{
			if (currtnd->left->n > currtnd->right->n)
				selnd = currtnd->left;
			else
				selnd = currtnd->right;
		}
		if (currtnd->n > selnd->n)
			break;
		exhval = currtnd->n;
		currtnd->n = selnd->n;
		selnd->n = exhval;
		currtnd = selnd;
	}
}

/**
 * heap_extract - Extracting root node of a Max Binary Heap
 * @root: double pointer to root node of heap
 * Return: value stored in the root node
 */

int heap_extract(heap_t **root)
{
	int extctval;
	heap_t *rtheap;
	heap_t *extctnd;

	if (!root || !*root)
		return (0);
	rtheap = *root;
	extctval = rtheap->n;
	if (!rtheap->left && !rtheap->right)
	{
		*root = NULL;
		free(rtheap);
		return (extctval);
	}
	trav_preorder(rtheap, &extctnd, bt_height(rtheap));
	rtheap->n = extctnd->n;
	if (extctnd->parent->right)
		extctnd->parent->right = NULL;
	else
		extctnd->parent->left = NULL;
	free(extctnd);
	trans_max_heap(rtheap);
	*root = rtheap;
	return (extctval);
}
