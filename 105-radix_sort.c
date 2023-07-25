#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum element from an array
 *
 * @array: The array
 * @size: Size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort - Sort an array of integers based on a specific digit
 *
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The exponent (digit position) to be used for sorting
 */
void count_sort(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (!output)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < SIZE_MAX; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        if (i == 0)
            break;
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix Sort
 *              algorithm (LSD - Least Significant Digit)
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        count_sort(array, size, exp);
        print_array(array, size);
    }
}
