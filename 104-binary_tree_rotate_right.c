#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Function right-rotates a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 * by: laila and mega
 *
 * Return: Pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pv, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pv = tree->left;
	temp = pv->right;
	pv->right = tree;
	tree->left = temp;
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
