#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Pointer to the node.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	{
		if (node->left == NULL && node->right == NULL)
			return (1);
		return (0);
	}
}

/**
 * calculate_height - Calculates the height of a binary tree.
 * @tree: The node that will act as the root when calculating the height.
 * @height: The current height of the tree.
 *
 * Return: The height of the tree.
 */
size_t calculate_height(const binary_tree_t *tree, size_t height)
{
	size_t left;
	size_t right;

	left = height;
	right = height;
	if (tree == NULL)
		return (0);
	left = left + calculate_height(tree->left, height);
	right = right + calculate_height(tree->right, height);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * binary_tree_height - Returns the height of a binary tree.
 * @tree: The node that will act as the root when calculating the height.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height;

	if (tree == NULL)
		return (0);
	height = 0;
	height = calculate_height(tree, height);
	return (height - 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);

	left = tree->left;
	right = tree->right;

	if (binary_tree_is_leaf(tree))
		return (1);

	if (left == NULL || right == NULL)
		return (0);

	if (binary_tree_height(left) == binary_tree_height(right))
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
			return (1);
	}
	return (0);
}
