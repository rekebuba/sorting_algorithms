#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * using the insertion sort algorithm
 *
 * @list: head pointer to a doubly linked list
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = (*list)->next;
	if (*list == NULL || temp == NULL)
		return;
	while (temp != NULL)
	{
		listint_t *ptr = temp;
		while (ptr->prev != NULL && ptr->n < ptr->prev->n)
		{
			swap_list(list, ptr->prev, ptr);
			print_list(*list);
			if (ptr->prev != NULL)
				ptr = ptr->prev->next;
		}
		temp = temp->next;
	}
}

/**
 * swap_list - swap the node themselves
 *
 * @a: pointer to the first node
 * @b: pointer to the second node
 * Return: Void
 */
void swap_list(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *ptr;

	if (a == NULL || b == NULL)
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
