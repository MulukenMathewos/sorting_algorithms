#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge two bitonic sequences in ascending or descending order
 * @array: Array to sort
 * @size: Number of elements to merge
 * @ascending: True for ascending order, false for descending
 */
void bitonic_merge(int *array, size_t size, int ascending)
{
	if (size > 1)
	{
		size_t i, mid = size / 2;

		bitonic_merge(array, mid, 1);
		bitonic_merge(array + mid, mid, 0);
		for (i = 0; i < mid; i++)
		{
			if ((array[i] > array[i + mid]) == ascending)
			{
				int temp = array[i];

				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}
		printf("Merging [%lu/%lu] (%s):\n", size, size, ascending ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		bitonic_sort(array, mid);
		bitonic_sort(array + mid, mid);
		bitonic_merge(array, size, 1);
		printf("Merging [%lu/%lu] (UP):\n", size, size);
		print_array(array, size);
	}
}
