#include "binary_trees.h"

/**
 * binary_tree_inorder - Applies function on a tree using inorder traversal
 * @tree: Pointer to tree
 * @func: Function pointer to use with a node's value
 */
void	binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
