#include "binary_trees.h"

/**
 * btree_height - Returns height of a binary tree
 * @tree: Pointer to tree
 * Return: Height of tree
 */
int		btree_height(const binary_tree_t *tree)
{
	int	left, right;

	if (tree && (tree->left || tree->right))
	{
		left = btree_height(tree->left);
		right = btree_height(tree->right);
		return (1 + (left > right ? left : right));
	}
	return (0);
}


/**
 * is_avl_util - Checks if a binary tree is an AVL tree
 * @tree: Pointer to tree
 * @min: Minimum accepted value for current node
 * @max: Maximum accepted value for current node
 * Return: 1 if tree is an AVL tree, 0 if not
 */
int		is_avl_util(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	if (abs(btree_height(tree->left) - btree_height(tree->right)) > 1)
		return (0);
	return (is_avl_util(tree->left, min, tree->n - 1)
		&& is_avl_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: Pointer to tree
 * Return: 1 if tree is an AVL tree, 0 if not
 */
int		binary_tree_is_avl(const binary_tree_t *tree)
{
	return (is_avl_util(tree, -2147483648, 2147483647));
}
