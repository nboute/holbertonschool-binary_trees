#include "binary_trees.h"

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
 * binary_tree_balance - Tells if a binary tree is balanced
 * @tree: Pointer to tree
 * Return: Balance factor of the tree
 */
int	binary_tree_balance(const binary_tree_t *tree)
{
	int	ret = 0;
	if (tree)
	{
		ret = (tree_height(tree->left)
			- tree_height(tree->right));
		if (!ret && !tree->left && tree->right)
			ret = -1;
		else if (!ret && !tree->right && tree->left)
			ret = 1;
	}
	return (ret);
}
