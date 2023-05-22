#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                     using the Cocktail Shaker Sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *tmp = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped) {
        swapped = 0;
        for (; (*list)->next != tmp; *list = (*list)->next)
        {
            if ((*list)->n > (*list)->next->n)
            {
                swap_nodes(list, &(*list)->next);
                print_list(*list);
                swapped = 1;
            }
        }
        for (; (*list)->prev != NULL && (*list)->prev != tmp; *list = (*list)->prev)
        {
            if ((*list)->n < (*list)->prev->n)
            {
                swap_nodes(&(*list)->prev, list);
                print_list(*list);
                swapped = 1;
            }
        }
        tmp = *list;
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **node1, listint_t **node2)
{
    listint_t *prev1, *next1, *prev2, *next2;

    prev1 = (*node1)->prev;
    next1 = (*node1)->next;
    prev2 = (*node2)->prev;
    next2 = (*node2)->next;

    if (prev1 != NULL)
        prev1->next = *node2;
    if (next2 != NULL)
        next2->prev = *node1;

    (*node2)->prev = prev1;
    (*node2)->next = *node1;
    (*node1)->prev = *node2;
    (*node1)->next = next2;

    *node1 = *node2;
    *node2 = next1;
}
