#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max - Check the max value through a binary tree
 * @tree: Pointer to the root
 * BY: laila and mega
 *
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int check_max(const binary_tree_t *tree)
{
	int temp1 = 1, temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = check_max(tree->right);
	}
	return (temp1 && temp2);
}
/**
 * binary_tree_is_heap - function checks if a binary tree is heap
 * @tree: pointer to the node
 * by: laila and mega
 *
 * Return: 1 in case BTS, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);
	if (!temp)
		return (0);
	return (check_max(tree));
}
