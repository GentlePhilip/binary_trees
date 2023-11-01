
#include "binary_trees.h"


avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
int balance(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);

/**
 * avl_insert - Updating an AVL Tree with a value.
 *
 * @tree: A pair of pointers to the AVL tree's root node for adding.
 *
 * @value: To store the value in the newly inserted node.
 *
 * Return: A pointer point to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}

/**
 * avl_insert_recursive - Adding a value iteratively to an AVL tree.
 *
 * @tree: An AVL tree's root node should get a double pointer.
 * @parent: The working node's parent node at the moment.
 *
 * @new: To hold the new node, a double pointer.
 * @value: To be inserted into the AVL tree is the value.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */

avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * balance - Determine the binary tree's balance factor.
 *
 * @tree: A pointer to the tree's root node where the balancing factor can be determined.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */

int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * height - Measuring the height of the binary tree.
 *
 * @tree: A pointer to a root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
