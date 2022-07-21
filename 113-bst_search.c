#include "binary_trees.h"

/**
 * bst_search - Search a value in a BST tree
 * @tree: Pointer to tree
 * @value: Value to search
 * Return: Pointer to node with corresponding value, or NULL if error
 */
bst_t	*bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));
	return ((bst_t *)tree);
}
