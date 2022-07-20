#include "binary_trees.h"

/**
 * binary_tree_height - Returns height of a binary tree
 * @tree: Pointer to tree
 * Return: Height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int	left, right;

	if (tree && (tree->left || tree->right))
	{
		left = binary_tree_height(tree->left);
		right = binary_tree_height(tree->right);
		return (1 + (left > right ? left : right));
	}
	return (0);
}
