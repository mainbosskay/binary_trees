#include "binary_trees.h"

/**
 * avl_sorted_build - Constructing an AVL tree from an array
 * @root: double pointer to root node of the subtree
 * @array: pointer to the array element
 * @minindx: minimum index
 * @maxindx: maximum index
 * Return: it is void
 */

void avl_sorted_build(avl_t **root, int *array, size_t minindx, size_t maxindx)
{
	avl_t *nwnode;
	size_t midindx;

	nwnode = NULL;
	if (maxindx - minindx > 1)
	{
		midindx = (maxindx - minindx) / 2 + minindx;
		nwnode = binary_tree_node(*root, array[midindx]);
		if (array[midindx] > (*root)->n)
		{
			(*root)->right = nwnode;
		}
		else if (array[midindx] < (*root)->n)
		{
			(*root)->left = nwnode;
		}
		avl_sorted_build(&nwnode, array, minindx, midindx);
		avl_sorted_build(&nwnode, array, midindx, maxindx);
	}
}

/**
 * sorted_array_to_avl - Building an AVL tree from an array
 * @array: pointer to first element of array to be converted
 * @size: number of element in the array
 * Return: pointer to root node of the created AVL tree, or NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avltree;
	size_t midindx;

	avltree = NULL;
	if (!array)
		return (NULL);
	midindx = (size - 1) / 2;
	avltree = binary_tree_node(NULL, array[midindx]);
	avl_sorted_build(&avltree, array, -1, midindx);
	avl_sorted_build(&avltree, array, midindx, size);
	return (avltree);
}
