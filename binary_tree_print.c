#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
* print_t - Stores recursively each level in an array of strings
* @tree: Pointer to the node to print
* @offset: Offset to print
* @depth: Depth of the node
* @s: Buffer
* Made by LAILO and MEGA
* Return: length of printed tree after process
*/

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, a;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (a = 0; a < width; a++)
		s[depth][offset + left + a] = b[a];
	if (depth && is_left)
	{
		for (a = 0; a < width + right; a++)
			s[depth - 1][offset + left + width / 2 + a] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (a = 0; a < left + width; a++)
			s[depth - 1][offset - width / 2 + a] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
* _height - Measures the height of a binary tree
* @tree: Pointer to the node to measures the height
* made by LAILO and MEGA
* Return: The height of the tree starting at @node
*/

static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
* binary_tree_print - Prints a binary tree
* Made by LAILO and MEGA
* @tree: Pointer to the root node of the tree to print
*/

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, a, b;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (a = 0; a < height + 1; a++)
	{
		s[a] = malloc(sizeof(**s) * 255);
		if (!s[a])
			return;
		memset(s[a], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (a = 0; a < height + 1; a++)
	{
		for (b = 254; b > 1; --b)
		{
			if (s[a][b] != ' ')
				break;
			s[a][b] = '\0';
		}
		printf("%s\n", s[a]);
		free(s[a]);
	}
	free(s);
}
