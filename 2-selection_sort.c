#include "sort.h"

/**
 * selection_sort - Sorts array of integers with selection sort algo.
 * @array: Array of integers.
 * @size: Size of array.
 */

void selection_sort(int *array, size_t size)
{
	int min, min_pos = -1;
	size_t i, j;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			min = array[i];
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < min)
				{
					min = array[j];
					min_pos = j;
				}
			}
			if (min < array[i])
			{
				array[min_pos] = array[i];
				array[i] = min;
				print_array(array, size);
			}
		}
	}
}
