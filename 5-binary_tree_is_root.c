#include "binary_trees.h"



/**
 * binary_tree_is_root - Verifies if a certain node is the root.
 *
 * @node: A reference to the node to examine.
 *
 * Return: 1 if node is a root, otherwise 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
