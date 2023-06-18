#include "binary_trees.h"

/**
 * max_nodes - Returns the maximum number of linear nodes in a binary tree.
 * @tree: Pointer to the root of the tree.
 *
 * Return: The maximum number of linear nodes.
 */
size_t max_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (max_nodes(tree->parent) + 1);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth.
 *
 * Return: The depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (max_nodes(tree) - 1);
}
