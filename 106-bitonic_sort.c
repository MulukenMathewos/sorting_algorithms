#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merge two bitonic sequences in ascending or descending order
 * @array: Array to sort
 * @start: Starting index of the sequence to merge
 * @count: Number of elements to merge
 * @direction: True for ascending order, false for descending
 */
void bitonic_merge(int *array, size_t start, size_t count, bool direction)
{
	if (count > 1)
	{
		size_t k = count / 2;

		for (size_t i = start; i < start + k; i++)
		{
			if ((array[i] > array[i + k]) == direction)
			{
				int temp = array[i];

				array[i] = array[i + k];
				array[i + k] = temp;
				printf("Merging [%lu/%lu] (%s):\n", count, count,
						direction ? "UP" : "DOWN");
				print_array(array, start + count);
			}
		}
		bitonic_merge(array, start, k, direction);
		bitonic_merge(array, start + k, k, direction);
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
	for (size_t k = 2; k <= size; k *= 2)
	{
		for (size_t j = k / 2; j > 0; j /= 2)
		{
			for (size_t i = 0; i < size; i += k)
			{
				bool direction = ((i / j) % 2) == 0;

				bitonic_merge(array, i, k, direction);
			}
		}
	}
}
