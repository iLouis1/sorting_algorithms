#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - This enumerats the card suits.
 * @SPADE: The spades suit.
 * @HEART: The hearts suit.
 * @CLUB:The clubs suit.
 * @DIAMOND: The diamonds suit.
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
 * @value: The value of the card
 * From "Ace" to "King"
 * @kind: The kind of the card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - The deck of card
 *
 * @card: The pointer to the card of the node
 * @prev: The pointer to the previous node of the list
 * @next: The pointer to the next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
