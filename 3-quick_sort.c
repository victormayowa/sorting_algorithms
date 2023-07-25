#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Lower bound index
 * @high: Higher bound index
 * @size: Number of elements in @array
 *
 * Return: Index of the partition
 */
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursive function to sort an array using Quick Sort
 *
 * @array: The array to be sorted
 * @low: Lower bound index
 * @high: Higher bound index
 * @size: Number of elements in @array
 */

void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm with Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
