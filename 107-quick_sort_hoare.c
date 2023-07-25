#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @array: The array containing the integers
 * @a_idx: The index of the first integer to swap
 * @b_idx: The index of the second integer to swap
 */
void swap(int *array, int a_idx, int b_idx)
{
    int temp = array[a_idx];
    array[a_idx] = array[b_idx];
    array[b_idx] = temp;
}

/**
 * partition_hoare - Partitions an array using the Hoare scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 * Return: The index of the pivot
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(array, i, j);
        print_array(array, size);
    }
}

/**
 * quicksort - Sorts an array using the quicksort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the array
 * @high: The ending index of the array
 * @size: The size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = partition_hoare(array, low, high, size);

        quicksort(array, low, pivot, size);
        quicksort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using
 *                    the quicksort algorithm with Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}

