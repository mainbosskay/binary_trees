#include "binary_trees.h"

/**
 * array_to_bst - Building a Binary Search Tree from an array
 * @array: pointer to first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to root node, or NULL
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t indx;
	bst_t *tree_rt;

	tree_rt = NULL;
	for (indx = 0 ; indx < size ; indx++)
	{
		bst_insert(&tree_rt, array[indx]);
	}
	return (tree_rt);
}
