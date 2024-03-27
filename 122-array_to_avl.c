#include "binary_trees.h"

/**
 * array_to_avl - Building an AVL tree from an array
 * @array: pointer to first element of the array
 * @size: number of element in the array
 * Return: pointer to root node of the created AVL tree, or NULL
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t indx;

	tree = NULL;
	if (array)
	{
		for (indx = 0 ; indx < size ; indx++)
		{
			avl_insert(&tree, *(array + indx));
		}
	}
	return (tree);
}
