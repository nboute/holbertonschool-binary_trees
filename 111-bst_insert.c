#include "binary_trees.h"

/**
 * bst_insert - Inserts a node in a bst tree
 * @tree: Adress of tree root
 * @value: Value for new node
 * Return: Pointer to inserted node
 */
bst_t	*bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		return (bst_insert(&(*tree)->left, value));
	}
	if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}
