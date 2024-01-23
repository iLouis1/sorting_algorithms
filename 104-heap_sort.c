#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Will turn a binary tree into complete binary heap.
 * @array: Array of integers representing a binary tree.
 * @size: Size of array/tree.
 * @base: The index of base row of the tree.
 * @root: The root node of binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Will sort an array of integers in ascending
 * order using heap sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Description: This implements sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		max_heapify(array, size, size, k);

	for (k = size - 1; k > 0; k--)
	{
		swap_ints(array, array + k);
		print_array(array, size);
		max_heapify(array, size, k, 0);
	}
}
