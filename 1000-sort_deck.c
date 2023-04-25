#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * card_cmp - compares two cards
 *
 * @c1: pointer to first card
 * @c2: pointer to second card
 *
 * Return: negative value if c1 < c2, positive value if c1 > c2, zero if equal
 */
int card_cmp(const void *c1, const void *c2)
{
	const card_t *card1 = ((const deck_node_t *)c1)->card;
	const card_t *card2 = ((const deck_node_t *)c2)->card;
	int val_cmp = strcmp(card1->value, card2->value);

	if (val_cmp != 0)
		return (val_cmp);
	return (card1->kind - card2->kind);
}

/**
 * sort_deck - sorts a deck of cards
 *
 * @deck: pointer to pointer to head of doubly-linked list of cards
 */
void sort_deck(deck_node_t **deck)
{
	size_t i, len = 0;
	deck_node_t **arr, *curr;

	if (deck == NULL || *deck == NULL)
		return;

	while (curr != NULL)
	{
		len++;
		curr = curr->next;
	}
	
	curr = *deck;
	arr = malloc(len * sizeof(deck_node_t *));
	for (i = 0; i < len; i++)
	{
		arr[i] = curr;
		curr = curr->next;
	}
	/* sort the array */
	qsort(arr, len, sizeof(deck_node_t *), card_cmp);
	/* convert array back to doubly-linked list */
	*deck = arr[0];
	(*deck)->prev = NULL;
	for (i = 1; i < len; i++)
	{
		arr[i]->prev = arr[i - 1];
		arr[i - 1]->next = arr[i];
	}
	arr[len - 1]->next = NULL;
	free(arr);
}
