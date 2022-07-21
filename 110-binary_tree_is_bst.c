#include "binary_trees.h"

/**
 * is_bst_util - Checks if a binary tree is a BST tree
 * @tree: Pointer to tree
 * @min: Minimum accepted value for current node
 * @max: Maximum accepted value for current node
 * Return: 1 if it's a BST tree, 0 if not
 */
int	is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst_util(tree->left, min, tree->n - 1)
		&& is_bst_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a BST tree
 * @tree: Pointer to tree
 * Return: 1 if it's a BST tree, 0 if not
 */
int	binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst_util(tree, -2147483648, 2147483647));
}
