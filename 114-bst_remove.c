#include "binary_trees.h"

/**
 * bst_min - Return minimum key value in a BST tree
 * @root: Pointer to tree
 * Return: Minimum key value in tree
 */
bst_t	*bst_min(bst_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Remove a node from a BST tree
 * @root: Root of tree
 * @value: Value of node to remove
 * Return: Root of tree
 */
bst_t	*bst_remove(bst_t *root, int value)
{
	bst_t	*tmp;

	if (!root)
		return (NULL);
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = bst_min(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
