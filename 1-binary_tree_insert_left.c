#include "binary_trees.h"

/**
 * binary_tree_insert_left - Creates a binary tree node and inserts it left
 * @parent: Parent of the node
 * @value: Value of the node's content
 * Return: Newly created node
 */
binary_tree_t	*binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t	*node;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->left = NULL;
	if (parent->left)
	{
		node->left = parent->left;
		if (node->left)
			node->left->parent = node;
	}
	parent->left = node;
	node->n = value;
	node->right = NULL;
	return (node);
}
