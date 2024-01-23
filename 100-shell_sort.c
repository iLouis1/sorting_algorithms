#include "sort.h"

/**
 * swap_ints - Will swap two integers in an array.
 * @a: First integer to be swaped.
 * @b: Second integer to be swaped.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Will sort an array of integers in ascending
 * order using shell sort algorithm.
 * @array: Array of an integer.
 * @size: Array size.
 *
 * Description: This uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, k, l;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			l = k;
			while (l >= gap && array[l - gap] > array[l])
			{
				swap_ints(array + l, array + (l - gap));
				l -= gap;
			}
		}
		print_array(array, size);
	}
}
