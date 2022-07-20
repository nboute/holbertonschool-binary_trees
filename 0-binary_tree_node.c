#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Parent of the node
 * @value: Value of the node's content
 * Return: Newly created node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
