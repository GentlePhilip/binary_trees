#include "binary_trees.h"



/**
 * binary_tree_insert_right - Adds a node to the right of another node.
 *
 * @parent: A reference to the node where the correct child should be inserted.
 * @value: Value to be kept in the fresh node.
 *
 *
 * Return: A pointer to the created node, NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
