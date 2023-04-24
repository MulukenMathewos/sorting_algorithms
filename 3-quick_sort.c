#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in
 * ascending order using Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursively sorts the array using Quick sort algorithm
 * @array: The array to be sorted
 * @start: Starting index of the array
 * @end: Ending index of the array
 * @size: Number of elements in @array
 *
 * Return: Nothing
 */
void quicksort_recursive(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = lomuto_partition(array, start, end, size);
		quicksort_recursive(array, start, pivot - 1, size);
		quicksort_recursive(array, pivot + 1, end, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort algorithm
 * @array: The array to be partitioned
 * @start: Starting index of the array
 * @end: Ending index of the array
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot element
 */
int lomuto_partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end], i = start - 1, j;

	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != end)
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
