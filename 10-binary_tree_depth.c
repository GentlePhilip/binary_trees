#include "binary_trees.h"


/**
 * binary_tree_depth - Determines the binary tree node's depth..
 *
 * @tree: The depth measurement node is shown by a pointer.
 *
 * Return: 0 if tree is NULL.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
