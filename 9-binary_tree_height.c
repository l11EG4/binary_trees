#include "binary_trees.h"

/**
* binary_tree_height - Measures the height of a
* binary tree
* @tree: A pointer to the root node of the
* tree to measure the height
* Return: If tree is NULL, your function must return 0, else return height
* Made by LAIlO and MEGATRON
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((l > r) ? l : r);
	}
	return (0);
}
