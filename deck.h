#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Represents the four kinds of a deck of cards
 * @SPADE: Represents the SPADE kind
 * @HEART: Represents the HEART kind
 * @CLUB: Represents the CLUB kind
 * @DIAMOND: Represents the DIAMOND kind
 * Description: This enum type defines the four kinds of a deck of cards,
 * namely spades, hearts, clubs, and diamonds. Each of these kinds
 * are assigned a unique integer value starting from 0 for SPADE,
 * 1 for HEART, 2 for CLUB, and 3 for DIAMOND.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int card_cmp(const void *c1, const void *c2);

#endif /* DECK_H */
