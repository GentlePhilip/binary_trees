#include "binary_trees.h"



int binary_tree_is_avl(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
size_t height(const binary_tree_t *tree);


/**
 * binary_tree_is_avl - Verifying a binary tree's validity as an AVL tree.
 *
 * @tree: To verify, a pointer leads to the tree's root node.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Verifying a binary tree's validity as an AVL tree.
 * @tree: To verify, a pointer leads to the tree's root node
 * @lo: The value of the least significant node that has been visited so far.
 *
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */

int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * height - Counting the height of the binary tree.
 * @tree: A reference to the tree's root node such that the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
