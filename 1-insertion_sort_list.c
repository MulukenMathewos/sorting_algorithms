#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the list to be sorted
 *
 * Description: You are not allowed to modify the integer n of a node. You have
 * to swap the nodes themselves.
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev_node = current->prev;
		next_node = current->next;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;

			current->prev = prev_node->prev;
			prev_node->next = next_node;
			prev_node->prev = current;
			next_node->prev = prev_node;

			prev_node = current->prev;
			print_list(*list);
		}
		current = next_node;
	}
}
