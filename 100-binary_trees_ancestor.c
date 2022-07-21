#include "binary_trees.h"

/**
 * tree_depth - Returns depth of a binary tree
 * @tree: Pointer to tree
 * Return: Depth of tree
 */
size_t tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + tree_depth(tree->parent));
	return (0);
}

/**
 * binary_trees_ancestor - Returns the lowest ancestor between two nodes
 *
 * @first: first node
 * @second: second node
 * Return: Pointer to ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t	depth1, depth2;
	binary_tree_t	*ptr1, *ptr2;

	depth1 = tree_depth(first);
	depth2 = tree_depth(second);

	if (!first || !second || !depth1 || !depth2)
		return (NULL);
	ptr1 = (binary_tree_t *)first;
	ptr2 = (binary_tree_t *)second;
	while (depth1 && depth2)
	{
		if (depth1 > depth2)
			ptr1 = ptr1->parent;
		else if (depth1 < depth2)
			ptr2 = ptr2->parent;
		else
		{
			if (ptr1 == ptr2)
				return (ptr1);
			ptr1 = ptr1->parent;
			ptr2 = ptr2->parent;
		}
		if (depth1 >= depth2)
			depth1--;
		if (depth1 <= depth2)
			depth2--;
	}
	if (ptr1 == ptr2)
		return (ptr1);
	return (NULL);
}
