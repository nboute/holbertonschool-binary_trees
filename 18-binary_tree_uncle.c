#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a binary tree node
 * @node: Pointer to node
 * Return: Pointer to uncle, or NULL if not found
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t	*parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	parent = node->parent;
	if (parent == parent->parent->left)
		return (parent->parent->right);
	return (parent->parent->left);
}
