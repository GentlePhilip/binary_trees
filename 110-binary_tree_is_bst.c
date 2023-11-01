#include "binary_trees.h"



int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_helper(const binary_tree_t *tree, int low, int high);

/**
 * binary_tree_is_bst- Determines whether a binary tree qualifies as a binary search tree.
 *
 * @tree: A  pointer to the tree's root node for inspection.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - Determines whether a binary tree qualifies as a binary search tree.
 *
 * @tree: A  pointer to the tree's root node for inspection.
 *
 * @low: The least significant node that has been visited so far.
 * @high: The biggest node visited thus far and its value.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */

int is_bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst_helper(tree->left, low, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, high));
	}

	return (1);
}
