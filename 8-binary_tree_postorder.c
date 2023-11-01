#include "binary_trees.h"


/**
 * binary_tree_postorder- A tree post-order traversal to process a binary..
 *
 * @tree: A pointer directing the user to the tree's root node.
 *
 * @func: A function pointer to be called for every node.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
