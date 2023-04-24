#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the list
 * @node: Pointer to the first node to swap
 * @next: Pointer to the second node to swap
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node, listint_t *next)
{
	listint_t *prev, *after;

	prev = node->prev;
	after = next->next;

	if (prev)
		prev->next = next;
	else
		*list = next;

	next->prev = prev;
	next->next = node;
	node->prev = next;
	node->next = after;

	if (after)
		after->prev = node;

	print_list((const listint_t *)*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the cocktail shaker sort algorithm
 *
 * @list: Pointer to a pointer to the first node of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left, *right;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (left = *list; left->next != NULL; left = left->next)
		{
			right = left->next;
			if (left->n > right->n)
			{
				swap_nodes(list, left, right);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (right = left; right->prev != NULL; right = right->prev)
		{
			left = right->prev;
			if (left->n > right->n)
			{
				swap_nodes(list, left, right);
				swapped = 1;
			}
		}
	} while (swapped);
}
