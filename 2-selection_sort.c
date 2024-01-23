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
 * selection_sort - Will sort an array of integers in ascending order
 * using selection sort algorithm.
 * @array: Array of integers.
 * @size: Size of an array.
 *
 * Description: Prints array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t k, l;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		min = array + k;
		for (l = k + 1; l < size; l++)
			min = (array[l] < *min) ? (array + l) : min;

		if ((array + k) != min)
		{
			swap_ints(array + k, min);
			print_array(array, size);
		}
	}
}
