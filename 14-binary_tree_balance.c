#include "binary_trees.h"

#define MAX(a, b) ((a) >= (b) ? (a) : (b))

/**
 * max_nodes - Returns the maximum number of linear nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The maximum number of linear nodes.
 */
size_t max_nodes(const binary_tree_t *tree)
{
	size_t left_m, right_m;

	if (!tree)
		return (0);

	left_m = max_nodes(tree->left);
	right_m = max_nodes(tree->right);

	return (MAX(left_m, right_m) + 1);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (max_nodes(tree));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The balance factor of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
