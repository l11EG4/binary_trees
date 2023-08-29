#include "binary_trees.h"

/**
 * bst_insert - Function inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * by : laila and mega
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur, *new;

	if (tree != NULL)
	{
		cur = *tree;

		if (cur == NULL)
		{
			new = binary_tree_node(cur, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < cur->n)
		{
			if (cur->left != NULL)
				return (bst_insert(&cur->left, value));

			new = binary_tree_node(cur, value);
			if (new == NULL)
				return (NULL);
			return (cur->left = new);
		}
		if (value > cur->n) /* insert in right subtree */
		{
			if (cur->right != NULL)
				return (bst_insert(&cur->right, value));

			new = binary_tree_node(cur, value);
			if (new == NULL)
				return (NULL);
			return (cur->right = new);
		}
	}
	return (NULL);
}
