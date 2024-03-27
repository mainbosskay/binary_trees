#include "binary_trees.h"

/**
 * binary_tree_ancestor - Finding the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: pointer to lowest common ancestor node of two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *currentnd;

	if (!first || !second)
		return (NULL);
	currentnd = (binary_tree_t *)second;
	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = currentnd;
		first = first->parent;
	}
	return (NULL);
}
