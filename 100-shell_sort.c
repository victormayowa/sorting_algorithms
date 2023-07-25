#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tp;

	tp = *a;
	*a = *b;
	*b = tp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t ornt, a, j;

	if (array == NULL || size < 2)
		return;

	for (ornt = 1; ornt < (size / 3);)
		ornt = ornt * 3 + 1;

	for (; ornt >= 1; ornt /= 3)
	{
		for (a = ornt; a < size; a++)
		{
			j = a;
			while (j >= ornt && array[j - ornt] > array[j])
			{
				swap_ints(array + j, array + (j - ornt));
				j -= ornt;
			}
		}
		print_array(array, size);
	}
}
