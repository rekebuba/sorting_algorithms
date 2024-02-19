#include "deck.h"

/**
 * sort_deck - sorts a deck of cards
 * The deck must be ordered From Ace to King
 * 
 * @deck: a double linked list having the the values
 * Return: Void 
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *curent;
    int swapped;

    do {
        swapped = 0;
        for (curent = *deck; curent->next; curent = curent->next)
        {
            if (check_word(deck, curent, curent->next))
            {
                curent = curent->prev;
                swapped = 1;
            }
            else if (atoi(curent->card->value) > atoi(curent->next->card->value) && atoi(curent->next->card->value) != 0)
            {
                swap_deck(deck, curent, curent->next);

                curent = curent->prev;
                swapped = 1;
            }
        }
    } while (swapped);

    do {
        swapped = 0;
        for (curent = *deck; curent->next; curent = curent->next)
        {
            if (curent->card->kind > curent->next->card->kind)
            {
                swap_deck(deck, curent, curent->next);
                curent = curent->prev;
                swapped = 1;
            }
        }
    } while (swapped);
}

/**
 * Get_word - get the value of the character givin
 * 
 * @word: the character passed
 * Return: the value
 */
int get_word(char word)
{
    switch (word)
    {
    case 'A':
        return 1;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    default:
        return 0;
    }
}

/**
 * check_word - checks the 4 words in the deck and sorts them
 * 
 * @deck: the deck card
 * @curent: the curent value of the card to be swapped
 * @next: the next value of the card to be swapped
 * Return: True if successfully swapped otherwise false
 */
bool check_word(deck_node_t **deck, deck_node_t *curent, deck_node_t *next)
{
    bool result = false;

    if (atoi(curent->card->value) == 0 && atoi(next->card->value) == 0)
    {
        if (get_word(curent->card->value[0]) > get_word((next->card->value[0])))
        {
            swap_deck(deck, curent, next);
            result = true;
        }
    }
    else if (atoi(curent->card->value) == 0 && atoi(next->card->value) != 0)
    {
        if (get_word(curent->card->value[0]) > atoi(next->card->value))
        {
            swap_deck(deck, curent, next);
            result = true;
        }
    }
    else if (atoi(curent->card->value) != 0 && atoi(next->card->value) == 0)
    {
        if (get_word(next->card->value[0]) < atoi(curent->card->value))
        {
            swap_deck(deck, curent, next);
            result = true;
        }
    }
    return (result);
}

/**
 * swap_deck - swap the node themselves
 *
 * @deck: a pointer to doubly linked deck
 * @a: pointer to the first node
 * @b: pointer to the second node
 * Return: Void
 */
void swap_deck(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
    deck_node_t *ptr;

    if (!a || !b)
        return;

    if (a->prev != NULL)
    {
        a->prev->next = b;
    }
    else
    {
        *deck = b;
    }
    ptr = b->next;
    b->next = a;
    b->prev = a->prev;
    a->next = ptr;
    a->prev = b;
    if (ptr != NULL)
        ptr->prev = a;
}
