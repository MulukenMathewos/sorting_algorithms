#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;

	print_array((const int *)a, 2);
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * the Quick sort algorithm with the Hoare partition scheme
 *
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int pivot, i = -1, j = size;

	if (size < 2)
		return;

	pivot = array[size - 1];
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			break;

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
	print_array(array, size);
	swap(&array[i], &array[size - 1]);

	quick_sort_hoare(array, i);
	quick_sort_hoare(array + i + 1, size - i - 1);
}
