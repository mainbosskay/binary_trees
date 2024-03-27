#include "binary_trees.h"

/**
 * array_to_heap - Building Max Binary Heap tree from an array
 * @array: pointer to first element of array to be converted
 * @size: number of element in array
 * Return: pointer to root node of the created Binary Heap
 */

heap_t *array_to_heap(int *array, size_t size)
{
	size_t indx;
	heap_t *rtheap;

	rtheap = NULL;
	if (array)
	{
		for (indx = 0 ; indx < size ; indx++)
		{
			heap_insert(&rtheap, *(array + indx));
		}
	}
	return (rtheap);
}
