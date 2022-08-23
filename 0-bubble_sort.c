#include "sort.h"

/**
 * bubble_sort - Sorts array of integers.
 * @array: Pointer to integers.
 * @size: Size of array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int aux, ordered = 1;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			aux = array[i];
			array[i] = array[i + 1];
			array[i + 1] = aux;
			print_array(array, size);
			ordered = 0;
		}
	}
	if (!ordered)
		bubble_sort(array, size);
}
