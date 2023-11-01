#include "binary_trees.h"



/**
 * array_to_avl - Using an array to create an AVL tree.
 *
 * @array: An identifier for the array's first element that needs to be changed.
 * @size: The element in the array's number.
 *
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, jndex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jndex = 0; jndex < index; jndex++)
		{
			if (array[jndex] == array[index])
				break;
		}
		if (jndex == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
