#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to first node
 * @b: Pointer to second node
 * @list: Pointer to the head of the list
 *
 * Return: No value returned
 */
void swap_nodes(listint_t **a, listint_t **b, listint_t **list)
{
	listint_t *prev_a, *next_b;

	prev_a = (*a)->prev;
	next_b = (*b)->next;

	if (prev_a)
		prev_a->next = *b;
	else
		*list = *b;

	(*b)->prev = prev_a;
	(*b)->next = *a;
	(*a)->prev = *b;
	(*a)->next = next_b;

	if (next_b)
		next_b->prev = *a;

	print_list((const listint_t *)*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 *
 * Return: No value returned
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	start = *list;
	end = NULL;
	swapped = 1;

	while (swapped == 1)
	{
		swapped = 0;

		while (start != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(&start, &(start->next), list);
				swapped = 1;
			}
			else
				start = start->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		end = start;
		start = start->prev;

		while (start != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(&start, &(start->next), list);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	}
}
