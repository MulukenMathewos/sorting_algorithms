#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *create_listint(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap(int *a, int *b);
void sift_down(int *array, size_t start, size_t end);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int left, int mid, int right);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void counting_sort1(int *array, size_t size, int exp);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *array, size_t size, int dir);
void bitonic_sort_helper(int *array, size_t size, int dir);
void quick_sort_hoare(int *array, size_t size);
void quicksort_recursive(int *array, int start, int end, size_t size);
int lomuto_partition(int *array, int start, int end, size_t size);

#endif
