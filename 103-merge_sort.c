#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays into a single sorted array
 *
 * @array: The array containing the two sub-arrays
 * @left: Pointer to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Pointer to the right sub-array
 * @right_s: Size of the right sub-array
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_s)
{
	size_t i = 0, j = 0, k = 0;
	int *merged_array = malloc((left_size + right_s) * sizeof(int));

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	while (i < left_size && j < right_s)
	{
		if (left[i] < right[j])
			merged_array[k++] = left[i++];
		else
			merged_array[k++] = right[j++];
	}
	while (i < left_size)
		merged_array[k++] = left[i++];
	while (j < right_s)
		merged_array[k++] = right[j++];
	for (i = 0; i < left_size + right_s; i++)
		array[i] = merged_array[i];
	printf("[Done]: ");
	print_array(array, left_size + right_s);
	free(merged_array);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge Sort algorithm (top-down approach)
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t middle;
	int *left;
	size_t left_size;
	int *right;
	size_t right_size;

	if (size < 2)
		return;
	middle = size / 2;
	left = array;
	left_size = middle;
	right = array + middle;
	right_size = size - middle;
	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, left, left_size, right, right_size);
}
