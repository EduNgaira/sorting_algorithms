#include "sort.h"
#include<stdio.h>

/**
 * insertion_sort_list -  sorts doubly linked list
 * in ascending order by insertion sort.
 * @list: given dl list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *store;

	if (!list)
		return;

	for (current = *list; current; current = current->next)
	{
		while (current->next && (current->next->n < current->n))
		{
			store = current->next;
			current->next = store->next;
			store->prev = current->prev;

			if (current->prev)
				current->prev->next = store;

			if (store->next)
				store->next->prev = current;

			current->prev = store;
			store->next = current;

			if (store->prev)
				current = store->prev;
			else
				*list = store;

			print_list(*list);
		}
	}
}
