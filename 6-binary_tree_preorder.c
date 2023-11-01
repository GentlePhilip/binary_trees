#include "binary_trees.h"



/**
 * binary_tree_preorder - Applies pre-order traversal to a binary tree.
 *
 * @tree: An arrow pointing to the tree's root node for traversal.
 *
 * @func: A function pointer to be called for every node.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
