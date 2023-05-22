#ifndef __SORT__
#define __SORT__
#include <stdlib.h>
#include <stdio.h>

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

/*======================================================================*/
/*=================         Printing Algoritms        ==================*/
/*======================================================================*/

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/*======================================================================*/
/*=================          sorting Algoritms        ==================*/
/*======================================================================*/

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void quick_s(int *array, int lo, int hi, size_t size);
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src);
void merge_partition(size_t lo, size_t hi, int *array, int *base);
void swap_root(int *array, size_t root, size_t hi, size_t size);
void swap_nodes(listint_t **node1, listint_t **node2);
void compare_swap(int *array, size_t i, size_t j, int dir);
void bitonic_merge(int *array, size_t low, size_t count, int dir);
#endif /* __SORT__ */
