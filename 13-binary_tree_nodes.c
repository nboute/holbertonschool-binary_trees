#include "binary_trees.h"

/**
 * binary_tree_nodes - Returns number of node with at least 1 child
 * in a binary tree
 * @tree: Pointer to tree
 * Return: Number of nodes with a child in tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int	ret = 0;

	if (tree)
		ret = binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
	if (tree && (tree->left || tree->right))
		return (ret + 1);
	return (ret);
}
