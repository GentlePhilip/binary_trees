#include "binary_trees.h"



/**
 * bst_search - A Binary Search Tree search for a value.
 *
 * @tree: A pointer directing the search to the BST root node.
 * @value: The tree's value to look up.
 *
 * Return: A reference pointing to the node when value equals value.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));

		return (bst_search(tree->right, value));
	}

	return (NULL);
}
