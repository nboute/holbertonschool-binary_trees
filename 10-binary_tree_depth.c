#include "binary_trees.h"

/**
 * binary_tree_depth - Returns depth of a binary tree
 * @tree: Pointer to tree
 * Return: Depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}
