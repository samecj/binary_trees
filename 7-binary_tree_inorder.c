#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs inorder traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *        The value in the node is passed as a parameter to the function.
 *
 * Description: This function traverses the binary
 * tree using inorder traversal,
 *       which means the left subtree is processed first, followed by
 *       the current node, and then the right subtree.
 *
 * Return: Nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
