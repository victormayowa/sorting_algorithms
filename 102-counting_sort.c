#include "sort.h"

/**
 * get_high - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_high(int *array, int size)
{
	int high, i;

	for (high = array[0], i = 1; i < size; i++)
	{
		if (array[i] > high)
			high = array[i];
	}

	return (high);
}

/**
 * caling_sort - Sort an array of integers in ascending order
 *                 using the caling sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the caling array after setting it up.
 */
void caling_sort(int *array, size_t size)
{
	int *cal, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_high(array, size);
	cal = malloc(sizeof(int) * (max + 1));
	if (cal == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		cal[i] = 0;
	for (i = 0; i < (int)size; i++)
		cal[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		cal[i] += cal[i - 1];
	print_array(cal, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[cal[array[i]] - 1] = array[i];
		cal[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(cal);
}
