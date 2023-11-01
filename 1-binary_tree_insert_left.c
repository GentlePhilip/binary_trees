#include "binary_trees.h"


/**
 * binary_tree_insert_left - Adding a node to another node as its left-child.
 *
 * @parent: A pointer pointing to the node to insert the left child in.
 * @value: The new node's value to be stored.
 *
 *
 * Return: A pointer pointing to the created node, NULL on failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
