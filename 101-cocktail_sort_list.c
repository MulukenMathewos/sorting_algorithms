#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 *
 * @node1: First node
 * @node2: Second node
 */
void swap_nodes(listint_t **node1, listint_t **node2)
{
	listint_t *tmp = (*node1)->prev;

	(*node1)->prev = (*node2);
	(*node2)->prev = tmp;
	if (tmp)
		tmp->next = (*node2);
	tmp = (*node2)->next;
	(*node2)->next = (*node1);
	(*node1)->next = tmp;
	if (tmp)
		tmp->prev = (*node1);
}

/**
 * cocktail_sort_list - Sort a doubly linked list using
 * the Cocktail shaker sort algorithm
 *
 * @list: Pointer to pointer to the head node of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list, *end = NULL;

	if (!list || !(*list) || !((*list)->next))
		return;
	while (swapped)
	{
		swapped = 0;
		while (start && start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(&start, &(start->next));
				if (!start->prev)
					*list = start;
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
		}
		end = start;
		if (!swapped)
			break;
		swapped = 0;
		while (end && end->prev != start)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(&(end->prev), &end);
				if (!end->next)
					end->next = NULL;
				print_list(*list);
				swapped = 1;
			}
			else
				end = end->prev;
		}
		start = end;
	}
}
