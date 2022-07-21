#include "binary_trees.h"


/**
 * binary_tree_perfect - Tells if a binary tree is perfect
 * @tree: Pointer to tree
 * @depth: Depth of tree
 * @level: Current level for recursion
 * Return: 1 if perfect, 0 if not
 */
int	binary_tree_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (!tree)
		return (1);
	if (!tree->left && !tree->right)
		return (depth == level ? 1 : 0);
	if (!tree->left || !tree->right)
		return (0);
	return (binary_tree_perfect(tree->left, depth, level + 1)
		&& binary_tree_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Tells if a binary tree is perfect
 * @tree: Pointer to tree
 * Return: 1 if perfect, 0 if not
 */
int	binary_tree_is_perfect(const binary_tree_t *tree)
{
	int				depth = 0;
	binary_tree_t	*ptr;

	if (!tree)
		return (0);
	ptr = (binary_tree_t *)tree;
	while (ptr && ptr->left)
	{
		depth++;
		ptr = ptr->left;
	}
	return (binary_tree_perfect(tree, depth, 0));
}
