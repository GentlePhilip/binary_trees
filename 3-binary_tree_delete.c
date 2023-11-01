#include "binary_trees.h"



/**
 * binary_tree_delete - Removes the whole binary tree.
 *
 *
 * @tree: A reference to the tree's root node for deletion.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
