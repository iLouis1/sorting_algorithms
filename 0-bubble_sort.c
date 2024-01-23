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
 * bubble_sort - Will sort an array of integers in ascending order.
 * @array: Array of integers to be sorted.
 * @size: Size of an rray.
 *
 * Description: Will print the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t k, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (k = 0; k < len - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap_ints(array + k, array + k + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
