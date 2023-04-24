#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = curr->next)
	{
		while (curr->prev != NULL && curr->prev->n > curr->n)
		{
			tmp = curr->prev;
			curr->prev = tmp->prev;

			if (tmp->prev != NULL)
				tmp->prev->next = curr;
			else
				*list = curr;

			tmp->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = tmp;
			curr->next = tmp;
			tmp->prev = curr;

			print_list(*list);
		}
	}
}
