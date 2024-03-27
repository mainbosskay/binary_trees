#include "binary_trees.h"

/**
 * bt_size - Calculating the size of a binary tree
 * @tree: pointer to tree to be calculated
 * Return: size of the calculated tree or 0
 */

size_t bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bt_size(tree->left) + bt_size(tree->right) + 1);
}

/**
 * heap_insert - Inserting a value in Max Binary Heap
 * @root: double pointer to root node of the Heap
 * @value: value to store in the node
 * Return: pointer to created node, or NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *currttree, *nwnode, *trav;
	int tond, remlf, subsz, bitmk, treelvl, tmpval;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	currttree = *root;
	tond = bt_size(currttree);
	remlf = tond;
	for (treelvl = 0, subsz = 1 ; remlf >= subsz ; subsz *= 2, treelvl++)
		remlf -= subsz;
	for (bitmk = 1 << (treelvl - 1) ; bitmk != 1 ; bitmk >>= 1)
		currttree = remlf & bitmk ? currttree->right : currttree->left;
	nwnode = binary_tree_node(currttree, value);
	remlf & 1 ? (currttree->right = nwnode) : (currttree->left = nwnode);
	trav = nwnode;
	for (; trav->parent && (trav->n > trav->parent->n) ; trav = trav->parent)
	{
		tmpval = trav->n;
		trav->n = trav->parent->n;
		trav->parent->n = tmpval;
		nwnode = nwnode->parent;
	}
	return (nwnode);
}
