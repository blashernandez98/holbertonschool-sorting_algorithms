#include "sort.h"

/**
 * _swap - Swaps two elements in an array.
 * @arr: Array
 * @a: Pos of element a of arr.
 * @b: Pos of element b of arr.
 * @size: Size of array.
 */

void _swap(int *arr, int a, int b, size_t size)
{
	int aux;

	if (arr)
	{
		aux = arr[a];
		arr[a] = arr[b];
		arr[b] = aux;
		print_array(arr, size);
	}
}

/**
 * partition - Partitions array arround pivot.
 * @arr: Array of integers.
 * @start: Starting position of sub array.
 * @end: Ending position of sub array.
 * @size: Size of full array.
 */

void partition(int *arr, int start, int end, size_t size)
{
	int big_left = -1, small_right = -1, i, pivot;

	if (start < end)
	{
		pivot  = end;
		for (i = start; i < pivot; i++)
		{
			if (arr[i] > arr[pivot])
			{
				big_left = i;
				break;
			}
		}
		if (big_left == -1)
		{
			partition(arr, start, end - 1, size);
			return;
		}
		for (i = pivot - 1; i > big_left; i--)
		{
			if (arr[i] < arr[pivot])
			{
				small_right = i;
				break;
			}
		}
		if (small_right == -1)
		{
			_swap(arr, pivot, big_left, size);
			partition(arr, start, big_left - 1, size);
			partition(arr, big_left + 1, end, size);
			return;
		}
		_swap(arr, big_left, small_right, size);
		big_left = -1;
		small_right = -1;
		partition(arr, start, end, size);
	}
}

/**
 * quick_sort - Function that sorts an array of integers using quick sort algo.
 * @array: Array of integers.
 * @size: Size of array.
 */

void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}
