#ifndef SORTING_ALGORITHM2
#define SORTING_ALGORITHM2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * enum kind_e - the four cards
 *
 * @SPADE: THE SPADE DECK
 * @HEART: THE HEART DECK
 * @CLUB: THE CLUB DECK
 * @DIAMOND: THE DIAMOND DECK
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
void swap_deck(deck_node_t **deck, deck_node_t *a, deck_node_t *b);
bool check_word(deck_node_t **deck, deck_node_t *curent, deck_node_t *next);
void cocktail_sort_deck(deck_node_t **deck);
int get_word(char word);
#endif
