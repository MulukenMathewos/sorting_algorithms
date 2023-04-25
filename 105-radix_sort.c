#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 * @exp: Exponent to calculate the significant digit
 *
 * Return: Nothing
 */
void counting_sort1(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max_num = 0;
	size_t i;
	int exp;

	if (size < 2 || !array)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	for (exp = 1; max_num / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
