#include "binary_trees.h"


/**
 * tree_traversal_levelorder - Applies function on a tree
 * using levelorder traversal
 * @tree: Pointer to tree
 * @func: Function pointer to use with a node's value
 * @level: Lever to start applying function to
 */
void tree_traversal_levelorder(const binary_tree_t *tree, void (*func)(int),
	size_t level)
{
	if (tree && func)
	{
		if (!level)
		{
			func(tree->n);
			return;
		}
		tree_traversal_levelorder(tree->left, func, level - 1);
		tree_traversal_levelorder(tree->right, func, level - 1);
	}
}


/**
 * tree_height - Returns height of a binary tree
 * @tree: Pointer to tree
 * Return: Height of tree
 */
static size_t tree_height(const binary_tree_t *tree)
{
	int	left, right;

	if (tree && (tree->left || tree->right))
	{
		left = tree_height(tree->left);
		right = tree_height(tree->right);
		return (1 + (left > right ? left : right));
	}
	return (0);
}

/**
 * binary_tree_levelorder - Applies function on a tree
 * using levelorder traversal
 * @tree: Pointer to tree
 * @func: Function pointer to use with a node's value
 */
void	binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t	i, height;

	height = tree_height(tree);
	for (i = 0; i <= height; i++)
		tree_traversal_levelorder(tree, func, i);
}
