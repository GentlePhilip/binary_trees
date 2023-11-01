#include "binary_trees.h"


/**
 * binary_tree_is_leaf - Verifies if a given node is a leaf.
 *
 * @node: A reference to the node to examine.
 *
 * Return: 1 if node is a leaf, otherwise 0.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
