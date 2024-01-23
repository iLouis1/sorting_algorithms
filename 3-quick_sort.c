#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - This orders subset of array of integers according to
 * the lomuto partition scheme (last element as pivot).
 * @array: Array of an integer.
 * @size: Size of an array.
 * @left: Starting index of the subset to order.
 * @right: The ending index of subset to order.
 *
 * Return: Final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - WIll implement quicksort algorithm through recursion.
 * @array: Array of integers to be sorted.
 * @size: Size of an array.
 * @left: Starting index of an array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: This uses Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Will sort an array of integers in ascending
 * order using quicksort algorithm.
 * @array: Array of integers.
 * @size: Size of an array.
 *
 * Description: This uses Lomuto partition scheme an pints
 * the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
