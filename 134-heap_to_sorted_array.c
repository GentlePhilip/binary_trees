#include "binary_trees.h"



/**
 * heap_to_sorted_array - A Binary Max Heap to a sorted array-integer conversion.
 *
 * @heap: A reference to the heap's root node for conversion.
 * @size: A location to keep track of the array's size.
 *
 * Return: Sorted in descending order
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	int extract, i = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);
	heap_size = binary_tree_size(heap);
	*size = heap_size;
	array = malloc(heap_size * sizeof(int));
	if (!array)
		return (NULL);
	while (heap)
	{
		extract = heap_extract(&heap);
		array[i] = extract;
		i++;
	}
	return (array);
}
