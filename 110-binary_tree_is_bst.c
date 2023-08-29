#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 * @l: The value of the smallest node visited thus far.
 * @h: The value of the largest node visited this far.
 * by : laila and mega
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int l, int h)
{
	if (tree != NULL)
	{
		if (tree->n < l || tree->n > h)
			return (0);
		return (is_bst_helper(tree->left, l, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, h));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Function checks if a binary tree is a valid binary ST.
 * @tree: Pointer to the root node of the tree to check.
 * by: laila and mega
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));

}
