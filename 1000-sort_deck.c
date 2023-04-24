#include <stddef.h>
#include <string.h>
#include "deck.h"

/* function to compare two cards */
int card_cmp(const void *c1, const void *c2)
{
    const card_t *card1 = ((const deck_node_t *)c1)->card;
    const card_t *card2 = ((const deck_node_t *)c2)->card;
    int val_cmp = strcmp(card1->value, card2->value);
    if (val_cmp != 0)
        return val_cmp;
    return card1->kind - card2->kind;
}

/* function to sort a deck of cards */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL)
        return;
    size_t len = 0;
    deck_node_t *curr = *deck;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }
    /* convert doubly-linked list to array */
    deck_node_t **arr = malloc(len * sizeof(deck_node_t *));
    curr = *deck;
    for (size_t i = 0; i < len; i++)
    {
        arr[i] = curr;
        curr = curr->next;
    }
    /* sort the array */
    qsort(arr, len, sizeof(deck_node_t *), card_cmp);
    /* convert array back to doubly-linked list */
    *deck = arr[0];
    (*deck)->prev = NULL;
    for (size_t i = 1; i < len; i++)
    {
        arr[i]->prev = arr[i - 1];
        arr[i - 1]->next = arr[i];
    }
    arr[len - 1]->next = NULL;
    free(arr);
}
