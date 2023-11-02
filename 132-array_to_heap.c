#include "binary_trees.h"



/**
 * array_to_heap - Creates a Max Binary Heap tree using an array.
 *
 * @array: A reference to the array's first element that has to be changed.
 * @size: The array's total number of elements.
 *
 * Return: A pointer to the root node of the created one, NULL on failure.
 */


heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int index;
	heap_t *root = NULL;

	for (index = 0; index < size; index++)
		heap_insert(&root, array[index]);

	return (root);
}
