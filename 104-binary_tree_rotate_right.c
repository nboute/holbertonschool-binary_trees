#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right
 * @tree: Pointer to tree
 * Return: Pointer to tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *ptr;

	if (!tree || !tree->left)
		return (NULL);
	ptr = tree->left;
	tree->left = ptr->right;
	if (ptr->right)
		ptr->right->parent = tree;
	ptr->right = tree;
	tree->parent = ptr;
	tree = ptr;
	ptr->parent = NULL;
	return (tree);
}
