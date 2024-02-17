#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: head to the double linked list
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = *list, *right = *list, *curent;

	while (right->next != NULL)
		right = right->next;

	while (left != right->prev && right != left)
	{
		for (curent = left; curent->next && curent != right; curent = curent->next)
		{
			if (curent->n > curent->next->n)
			{
				swap_list(list, curent, curent->next);
				print_list(*list);
				curent = curent->prev;
			}
			if (curent == right)
				right = right->next;
		}

		for (curent = curent->prev; curent->prev && curent != left; curent = curent->prev)
		{
			if (curent->prev->n > curent->n)
			{
				swap_list(list, curent->prev, curent);
				print_list(*list);
				curent = curent->next;
			}
			if (curent == left)
				left = left->prev;
		}
		left = curent->next;
		right = right->prev;
	}
}

/**
 * swap_list - swap the node themselves
 *
 * @list: a pointer to doubly linked list
 * @a: pointer to the first node
 * @b: pointer to the second node
 * Return: Void
 */
void swap_list(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *ptr;

	if (!a || !b)
		return;

	if (a->prev != NULL)
	{
		a->prev->next = b;
	}
	else
	{
		*list = b;
	}
	ptr = b->next;
	b->next = a;
	b->prev = a->prev;
	a->next = ptr;
	a->prev = b;
	if (ptr != NULL)
		ptr->prev = a;
}
