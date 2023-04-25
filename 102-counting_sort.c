#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array = NULL, *sorted_array = NULL;
    int i, j, k;

    if (!array || size < 2)
        return;

    k = array[0];
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > k)
            k = array[i];
    }

    count_array = malloc(sizeof(int) * (k + 1));
    if (!count_array)
        return;

    sorted_array = malloc(sizeof(int) * size);
    if (!sorted_array)
    {
        free(count_array);
        return;
    }

    for (i = 0; i <= k; i++)
        count_array[i] = 0;

    for (j = 0; j < (int)size; j++)
        count_array[array[j]] += 1;

    for (i = 1; i <= k; i++)
        count_array[i] += count_array[i - 1];

    for (j = size - 1; j >= 0; j--)
    {
        sorted_array[count_array[array[j]] - 1] = array[j];
        count_array[array[j]] -= 1;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sorted_array[i];

    print_array(count_array, k + 1);

    free(count_array);
    free(sorted_array);
}
