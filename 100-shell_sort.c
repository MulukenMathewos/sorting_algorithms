#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the
 *              Shell sort algorithm and the Knuth sequence.
 *
 * @array: The array to sort.
 * @size: The size of the array to sort.
 *
 * Description: Prints the array each time the interval is decreased.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
