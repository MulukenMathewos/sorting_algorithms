#include "sort.h"

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 *                Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_recursive(array, size, 0, size, 1);
}

/**
 * bitonic_recursive - Recursively sorts an array of integers in ascending order
 *                     using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * @start: The starting index of the subarray to be sorted
 * @count: The number of elements in the subarray to be sorted
 * @order: The order of sorting (1 for ascending, -1 for descending)
 */
void bitonic_recursive(int *array, size_t size, size_t start, size_t count, int order)
{
    size_t half = count / 2;
    int swapped = 0;

    if (count > 1)
    {
        printf("Merging [%lu/%lu] (%s):\n", count, size, order == 1 ? "UP" : "DOWN");
        print_array(array + start, count);

        for (size_t i = start; i < start + half; i++)
        {
            if ((array[i] > array[i + half]) == order)
            {
                swap(&array[i], &array[i + half]);
                swapped = 1;
            }
        }

        if (swapped)
        {
            bitonic_recursive(array, size, start, half, order);
            bitonic_recursive(array, size, start + half, half, order);
        }
    }

    if (count == size)
    {
        printf("Result [%lu/%lu] (%s):\n", count, size, order == 1 ? "UP" : "DOWN");
        print_array(array + start, count);
    }
}

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

    printf("Result [%d/%d] (UP):\n", *a, *b);
    print_array((const int *)a, 2);
}
