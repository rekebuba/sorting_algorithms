#include "deck.h"

void sort_deck(deck_node_t **deck)
{
    cocktail_sort_deck(*deck);
}

/**
 * cocktail_sort_deck - sorts a doubly linked deck of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @deck: head to the double linked deck
 * Return: Void
 */
void cocktail_sort_deck(deck_node_t **deck)
{
    deck_node_t *left = *deck, *right = *deck, *curent;

    while (right->next != NULL)
        right = right->next;

    while (left != right->prev && right != left)
    {
        for (curent = left; curent->next && curent != right; curent = curent->next)
        {
            if (atoi(curent->card->value) == 0 || atoi(curent->next->card->value) == 0)
            {
                check_word(*deck, curent, curent->next);
                curent = curent->prev;
            }
            else if (atoi(curent->card->value) > atoi(curent->next->card->value) && curent->card->kind >= curent->next->card->kind)
            {
                swap_deck(deck, curent, curent->next);
                print_deck(*deck);
                curent = curent->prev;
            }
            if (curent == right)
                right = right->next;
        }

        for (curent = curent->prev; curent->prev && curent != left; curent = curent->prev)
        {
            if (atoi(curent->prev->card->value) == 0 || atoi(curent->card->value) == 0)
            {
                check_word(*deck, curent->prev, curent);
                curent = curent->next;
            }
            else if (atoi(curent->prev->card->value) > atoi(curent->card->value) && curent->prev->card->kind >= curent->card->kind)
            {
                swap_deck(deck, curent->prev, curent);
                print_deck(*deck);
                curent = curent->next;
            }
            if (curent == left)
                left = left->prev;
        }
        left = curent->next;
        right = right->prev;
    }
}

void check_word(deck_node_t **deck, deck_node_t *curent, deck_node_t *next)
{
    int words['Q' + 1] = {
        ['A'] = 1,
        ['J'] = 11,
        ['Q'] = 12,
        ['J'] = 13,
    };

    int value_1 = atoi(curent->card->value);
    int value_2 = atoi(next->card->value);

    int value_1_index = atoi(&curent->card->value[0]);
    int value_2_index = atoi(&next->card->value[0]);

    if (value_1 == 0 && value_2 == 0)
    {
        if (words[value_1_index] > words[value_2_index] && curent->card->kind >= next->card->kind)
        {
            swap_deck(deck, curent, next);
            print_deck(*deck);
        }
    }
    else if (words[value_1_index] > value_2 && curent->card->kind >= next->card->kind)
    {
        swap_deck(deck, curent, next);
        print_deck(*deck);
    }
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
