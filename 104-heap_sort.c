#include "sort.h"

/**
 * swap - Swaps two values in an array
 *
 * @array: The array containing the values to swap
 * @i: The index of the first value to swap
 * @j: The index of the second value to swap
 *
 * Return: Nothing
 */
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * sift_down - Moves an element down the heap until it is in the correct position
 *
 * @array: The array containing the heap
 * @start: The index of the element to move down the heap
 * @end: The index of the last element in the heap
 * @size: The size of the array
 *
 * Return: Nothing
 */
void sift_down(int *array, int start, int end, size_t size)
{
    int root = start;

    while ((root * 2) + 1 <= end)
    {
        int child = (root * 2) + 1;
        int swap_idx = root;

        if (array[swap_idx] < array[child])
            swap_idx = child;

        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;

        if (swap_idx == root)
            return;

        swap(array, root, swap_idx);
        print_array(array, size);

        root = swap_idx;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             heap sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
    int end = size - 1;

    for (int start = (end - 1) / 2; start >= 0; start--)
        sift_down(array, start, end, size);

    while (end > 0)
    {
        swap(array, 0, end);
        print_array(array, size);
        end--;
        sift_down(array, 0, end, size);
    }
}
