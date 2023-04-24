#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
    if (!list || !(*list) || !((*list)->next))
        return;

    listint_t *current = (*list)->next;

    while (current)
    {
        listint_t *temp = current->prev;

        while (temp && temp->n > current->n)
        {
            if (temp->prev)
                temp->prev->next = current;
            else
                (*list) = current;

            current->prev = temp->prev;
            temp->prev = current;
            temp->next = current->next;
            current->next = temp;

            print_list(*list);
            temp = current->prev;
        }

        current = current->next;
    }
}
