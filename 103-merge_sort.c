#include <stdlib.h>
#include <stdio.h>

#include "sort.h"

/**
 * merge - Merges two subarrays of an array of integers in ascending order
 *
 * @array: Array to be sorted
 * @left: Start index of left subarray
 * @mid: End index of left subarray, start index of right subarray
 * @right: End index of right subarray
 *
 * Return: void
 */
void merge(int *array, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *left_arr = malloc(n1 * sizeof(int));
	int *right_arr = malloc(n2 * sizeof(int));

	if (!left_arr || !right_arr)
		return;

	for (i = 0; i < n1; i++)
		left_arr[i] = array[left + i];
	for (j = 0; j < n2; j++)
		right_arr[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {
		if (left_arr[i] <= right_arr[j]) {
			array[k] = left_arr[i];
			i++;
		} else {
			array[k] = right_arr[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		array[k] = left_arr[i];
		i++;
		k++;
	}

	while (j < n2) {
		array[k] = right_arr[j];
		j++;
		k++;
	}

	free(left_arr);
	free(right_arr);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int mid = size / 2;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, 0, mid - 1, size - 1);
}
