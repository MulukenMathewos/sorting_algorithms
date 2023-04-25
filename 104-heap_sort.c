#include "sort.h"
#include <stdio.h>

/**
 * sift_down - repair the heap whose root element is at index 'start'
 * @array: Array to sort
 * @start: index of the root element in the heap
 * @end: index of the last element in the heap
 *
 * Return: void
 */
static void sift_down(int *array, size_t start, size_t end)
{
    size_t root = start;

    while ((2 * root + 1) <= end)
    {
        size_t child = 2 * root + 1;
        size_t swap = root;

        if (array[swap] < array[child])
            swap = child;

        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap != root)
        {
            int tmp = array[root];
            array[root] = array[swap];
            array[swap] = tmp;
            print_array(array, end + 1);
            root = swap;
        }
        else
        {
            return;
        }
    }
}

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
    int i;

    if (size < 2 || !array)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, i, size - 1);

    for (i = size - 1; i > 0; i--)
    {
        int tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        print_array(array, size);
        sift_down(array, 0, i - 1);
    }
}
