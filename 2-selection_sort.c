#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tp;

	tmp = *a;
	*a = *b;
	*b = tp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *least;
	size_t a, j;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		least = array + a;
		for (j = a + 1; j < size; j++)
			least = (array[j] < *least) ? (array + j) : least;

		if ((array + a) != least)
		{
			swap_ints(array + a, least);
			print_array(array, size);
		}
	}
}
