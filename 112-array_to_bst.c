#include "binary_trees.h"

/**
 * array_to_bst - Converts an array of int to a bst tree
 * @array: Array of ints
 * @size: Size of array
 * Return: Pointer to created tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t	i;
	bst_t	*tree = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
