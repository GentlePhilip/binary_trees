#include "binary_trees.h"



/**
 * binary_tree_rotate_left - Rotates a binary tree left.
 *
 * @tree: A pointer to the rotating tree's root node.
 *
 * Return: A reference to the tree's newly rotated root node.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *pivot, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tmp = pivot->left;
	pivot->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}
