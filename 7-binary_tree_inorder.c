#include "binary_trees.h"



/**
 * binary_tree_inorder - Utilizes an in-order traversal in a binary tree
 *
 * @tree: An arrow pointing to the tree's root node for traversal.
 *
 * @func: A function pointer to be called for every node.
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
