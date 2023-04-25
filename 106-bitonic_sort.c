#include "sort.h"
#include <stdio.h>

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 *                Bitonic sort algorithm
 * @array: pointer to the array of integers to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_helper(array, size, 1);
}

/**
 * bitonic_sort_helper - recursive function to implement Bitonic sort
 * @array: pointer to the array of integers to be sorted
 * @size: size of the array
 * @dir: sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_helper(int *array, size_t size, int dir)
{
	if (size < 2)
		return;

	bitonic_sort_helper(array, size / 2, 1);
	bitonic_sort_helper(array + size / 2, size / 2, 0);

	bitonic_merge(array, size, dir);
}

/**
 * bitonic_merge - merges two subarrays in a Bitonic sequence
 * @array: pointer to the array of integers to be sorted
 * @size: size of the array
 * @dir: sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	int i, temp;
	int k = size / 2;

	for (i = 0; i < k; i++)
	{
		if ((array[i] > array[i + k]) == dir)
		{
			/* swap array[i] and array[i+k] */
			temp = array[i];
			array[i] = array[i + k];
			array[i + k] = temp;
			printf("Swap: %d %d\n", array[i], array[i + k]);
		}
	}
	if (size > 2)
	{
		bitonic_merge(array, k, dir);
		bitonic_merge(array + k, k, dir);
	}
}
