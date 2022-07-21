#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left
 * @tree: Pointer to tree
 * Return: Pointer to tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *ptr;

	if (!tree || !tree->right)
		return (NULL);
	ptr = tree->right;
	tree->right = ptr->left;
	if (ptr->left)
		ptr->left->parent = tree;
	ptr->left = tree;
	tree->parent = ptr;
	tree = ptr;
	ptr->parent = NULL;
	return (tree);
}
