#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of array.
 *
 * Return: The maximum integer in the array.
 */

int get_max(int *array, int size)
{
	int max, k;

	for (max = array[0], k = 1; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}

	return (max);
}

/**
 * radix_counting_sort - Will sort significant digits of an array of integers
 * in ascending order using counting sort algorithm.
 * @array: Array of integers.
 * @size: Size of array.
 * @sig: Significant digit to sort on.
 * @buff: Buffer to store sorted array.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t k;

	for (k = 0; k < size; k++)
		count[(array[k] / sig) % 10] += 1;

	for (k = 0; k < 10; k++)
		count[k] += count[k - 1];

	for (k = size - 1; (int)k >= 0; k--)
	{
		buff[count[(array[k] / sig) % 10] - 1] = array[k];
		count[(array[k] / sig) % 10] -= 1;
	}

	for (k = 0; k < size; k++)
		array[k] = buff[k];
}

/**
 * radix_sort - Will sort an array of integers in ascending
 * order using radix sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Will implement LSD radix sort algorithm. 
 * Prints array after each significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);

	if (buff == NULL)
		return;

	max = get_max(array, size);

	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
