#include "binary_trees.h"


bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);


/**
 * bst_remove - Eliminates a node from a Binary Search Tree.
 *
 * @root: A reference to the tree's root node, from which you will delete a node.
 * @value: The number to take out of the tree.
 *
 * Return: An identifier for the tree's new root node following the removal of.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

/**
 * bst_remove_recursive - Eliminates a node iteratively from a binary search tree.
 * @root: To remove a node from the BST, a pointer to the root node.
 * @node: A reference to the BST's active node.
 *
 * @value: The number to be eliminated from the BST.
 *
 * Return: Following deletion, a reference to the root node.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_delete - Takes a node off of the binary search tree..
 * @root: A pointer pointing to the BST's root node.
 * @node: A reference indicating which BST node should be deleted.
 *
 * Return: A reference to the newly deleted root node.
 */

bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * inorder_successor - Gives the binary search tree's lowest value back..
 * @root: A pointer directing the search to the BST root node.
 *
 * Return: The minimal value in @tree.
 */

bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
