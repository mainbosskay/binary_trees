#include "binary_trees.h"

/**
 * mem_realloc - Adjusting memory allocation
 * @prevmem: pointer to existing memory block
 * @oldmemsz: size of original memory block
 * @newmemsz: size of desired memory block
 * Return: it is void
 */

void *mem_realloc(void *prevmem, unsigned int oldmemsz, unsigned int newmemsz)
{
	void *nwmem;
	unsigned int indx;
	unsigned int minsz = oldmemsz < newmemsz ? oldmemsz : newmemsz;

	if (newmemsz == oldmemsz)
		return (prevmem);
	if (prevmem)
	{
		if (newmemsz == 0)
		{
			free(prevmem);
			return (NULL);
		}
		nwmem = malloc(newmemsz);
		if (nwmem)
		{
			for (indx = 0 ; indx < minsz ; indx++)
				*((char *)nwmem + indx) = *((char *)prevmem + indx);
			free(prevmem);
			return (nwmem);
		}
		free(prevmem);
		return (NULL);
	}
	else
	{
		nwmem = malloc(newmemsz);
		return (nwmem);
	}
}

/**
 * heap_to_sorted_array - Converting Binary Max Heap to sorted array of ints
 * @heap: pointer to root node
 * @size: address to store size of the array
 * Return: pointer to sorted array in descending order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr = NULL;
	int extval;
	heap_t *currtnd;
	size_t arrsz = 0;

	if (heap)
	{
		currtnd = heap;
		while (currtnd)
		{
			extval = heap_extract(&currtnd);
			arr = mem_realloc(arr, sizeof(int) * arrsz, sizeof(int) * (arrsz + 1));
			*(arr + arrsz) = extval;
			arrsz++;
		}
	}
	if (size)
		*size = arrsz;
	return (arr);
}
