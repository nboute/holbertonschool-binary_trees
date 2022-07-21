#include "binary_trees.h"

/**
 * btree_count_nodes - Counts number of nodes in a binary tree
 * @tree: Pointer to tree
 * Return: Number of nodes
 */
int	btree_count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + btree_count_nodes(tree->left) + btree_count_nodes(tree->right));
}

/**
 * btree_is_complete_recurs - Checks if a binary tree is 'complete'
 * @tree: Pointer to tree
 * @index: Index of current node
 * @nodes: Number of nodes in tree
 * Return: 1 if complete, 0 if not
 */
int		btree_is_complete_recurs(binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (btree_is_complete_recurs(tree->left, index * 2 + 1, nodes)
	&& btree_is_complete_recurs(tree->right, index * 2 + 2, nodes));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is 'complete'
 * @tree: Pointer to tree
 * Return: 1 if complete, 0 if not
 */
int		binary_tree_is_complete(const binary_tree_t *tree)
{
	int	nodes;

	if (!tree)
		return (0);
	nodes = btree_count_nodes(tree);
	return (btree_is_complete_recurs((binary_tree_t *)tree, 0, nodes));
}
