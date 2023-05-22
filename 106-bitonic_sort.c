#include "sort.h"

/**
 * print_array - Prints the elements of an array
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * compare_swap - Compares and swaps two elements based on direction
 * @array: The array containing the elements
 * @i: The index of the first element
 * @j: The index of the second element
 * @dir: The sorting direction (1 for ascending, 0 for descending)
 */
void compare_swap(int *array, size_t i, size_t j, int dir)
{
	if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
	{
		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;
		printf("Result [%lu/%lu] (%s):\n", j, i + 1, (dir == 1) ? "UP" : "DOWN");
		print_array(array, i + 1);
	}
}

/**
 * bitonic_merge - Recursively performs the merging step of Bitonic sort
 * @array: The array to be sorted
 * @low: The starting index of the merge
 * @count: The number of elements to be merged
 * @dir: The sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
			compare_swap(array, i, i + k, dir);

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size <= 1)
		return;

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);

	bitonic_sort(array, size / 2);
	bitonic_sort(array + size / 2, size / 2);
	bitonic_merge(array, 0, size, 1);
}
