#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array to be sorted
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr;
	int max_num, i, j;

	if (!array || size < 2)
		return;

	max_num = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}

	count_arr = malloc(sizeof(int) * (max_num + 1));
	if (!count_arr)
		return;

	for (i = 0; i <= max_num; i++)
		count_arr[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_arr[array[i]]++;

	printf("%d", count_arr[0]);
	for (i = 1; i <= max_num; i++)
		printf(", %d", count_arr[i]);
	printf("\n");

	j = 0;
	for (i = 0; i <= max_num; i++)
	{
		while (count_arr[i]--)
			array[j++] = i;
	}
	free(count_arr);
}
