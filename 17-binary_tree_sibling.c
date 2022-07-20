#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a binary tree node
 * @node: Pointer to node
 * Return: Pointer to sibling, or NULL if not found
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
