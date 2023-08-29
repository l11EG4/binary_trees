#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * by : laila and mega
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pv, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pv = tree->right;
	temp = pv->left;
	pv->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pv;
	pv->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pv;
		else
			temp->right = pv;
	}

	return (pv);
}
