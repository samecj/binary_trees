#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes with at
 * least one child in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The number of nodes with at least one child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
