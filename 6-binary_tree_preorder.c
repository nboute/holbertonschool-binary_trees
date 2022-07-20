#include "binary_trees.h"

/**
 * binary_tree_preorder - Applies function on a tree using preorder traversal
 * @tree: Pointer to tree
 * @func: Function pointer to use with a node's value
 */
void	binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
