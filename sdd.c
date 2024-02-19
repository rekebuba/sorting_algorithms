#include "deck.h"

void print_deck(const deck_node_t *deck)
{
    size_t i;
    char kinds[4] = {'S', 'H', 'C', 'D'};

    i = 0;
    while (deck)
    {
        if (i)
            printf(", ");
        printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
        if (i == 12)
            printf("\n");
        i = (i + 1) % 13;
        deck = deck->next;
    }
}

deck_node_t *init_deck(const card_t cards[52])
{
    deck_node_t *deck;
    deck_node_t *node;
    size_t i;

    i = 52;
    deck = NULL;
    while (i--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        node->card = &cards[i];
        node->next = deck;
        node->prev = NULL;
        if (deck)
            deck->prev = node;
        deck = node;
    }
    return (deck);
}

int main(void)
{
    card_t cards[52] = {
        {"Jack", CLUB},
        {"4", HEART},
        {"3", HEART},
        {"3", DIAMOND},
        {"Queen", HEART},
        {"5", HEART},
        {"5", SPADE},
        {"10", HEART},
        {"6", HEART},
        {"5", DIAMOND},
        {"6", SPADE},
        {"9", HEART},
        {"7", DIAMOND},
        {"Jack", SPADE},
        {"Ace", DIAMOND},
        {"9", CLUB},
        {"Jack", DIAMOND},
        {"7", SPADE},
        {"King", DIAMOND},
        {"10", CLUB},
        {"King", SPADE},
        {"8", CLUB},
        {"9", SPADE},
        {"6", CLUB},
        {"Ace", CLUB},
        {"3", SPADE},
        {"8", SPADE},
        {"9", DIAMOND},
        {"2", HEART},
        {"4", DIAMOND},
        {"6", DIAMOND},
        {"3", CLUB},
        {"Queen", CLUB},
        {"10", SPADE},
        {"8", DIAMOND},
        {"8", HEART},
        {"Ace", SPADE},
        {"Jack", HEART},
        {"2", CLUB},
        {"4", SPADE},
        {"2", SPADE},
        {"2", DIAMOND},
        {"King", CLUB},
        {"Queen", SPADE},
        {"Queen", DIAMOND},
        {"7", CLUB},
        {"7", HEART},
        {"5", CLUB},
        {"10", DIAMOND},
        {"4", CLUB},
        {"King", HEART},
        {"Ace", HEART},
    };
    deck_node_t *deck;

    deck = init_deck(cards);
    print_deck(deck);
    printf("\n");
    sort_deck(&deck);
    printf("\n");
    print_deck(deck);
    return (0);
}

void sort_deck(deck_node_t **deck)
{
    deck_node_t *ptr = *deck, *curent;

    int swapped;
    do
    {
        swapped = 0;
        for (curent = *deck; curent->next; curent = curent->next)
        {
            if (check_word(deck, curent, curent->next))
            {
                // print_deck(*deck);
                // printf("\n___________\n");
                curent = curent->prev;
                swapped = 1;
            }
            else if (atoi(curent->card->value) > atoi(curent->next->card->value) && atoi(curent->next->card->value) != 0)
            {
                swap_deck(deck, curent, curent->next);
                // print_deck(*deck);
                // printf("\n___________\n");
                curent = curent->prev;
                swapped = 1;
            }
        }
    } while (swapped);
    do
    {
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
 * cocktail_sort_deck - sorts a doubly linked deck of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @deck: head to the double linked deck
 * Return: Void
 */

bool check_word(deck_node_t **deck, deck_node_t *curent, deck_node_t *next)
{
    int words['Q' + 1] = {
        ['A'] = 1,
        ['J'] = 11,
        ['Q'] = 12,
        ['K'] = 13,
    };
    bool result = false;

    if (atoi(curent->card->value) == 0 && atoi(next->card->value) == 0)
    {
        if (words[curent->card->value[0]] > words[(next->card->value[0])])
        {
            swap_deck(deck, curent, next);
            // print_deck(*deck);
            // printf("\n___________\n");
            result = true;
        }
    }
    else if (atoi(curent->card->value) == 0 && atoi(next->card->value) != 0)
    {
        if (words[curent->card->value[0]] > atoi(next->card->value))
        {
            swap_deck(deck, curent, next);
            // print_deck(*deck);
            // printf("\n___________\n");
            result = true;
        }
    }
    else if (atoi(curent->card->value) != 0 && atoi(next->card->value) == 0)
    {
        if (words[next->card->value[0]] < atoi(curent->card->value))
        {
            swap_deck(deck, curent, next);
            // print_deck(*deck);
            // printf("\n___________\n");
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
