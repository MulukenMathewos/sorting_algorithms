#include "sort.h"

/**
 * swap - swap two integer values
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - partition array using hoare scheme
 * @array: array to partition
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of the array
 * Return: pivot index
 */
int hoare_partition(int *array, int low, int high, size_t size)
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
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare - recursive quicksort function using hoare partition
 * @array: array to sort
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quicksort_hoare(array, low, pivot, size);
		quicksort_hoare(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array using quicksort algorithm
 * with hoare partition scheme
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
	{
		quicksort_hoare(array, 0, size - 1, size);
	}
}
