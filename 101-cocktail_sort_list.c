#include "sort.h"
#include<stdio.h>

/**
 * nodes_swap - swaps nodes in a list
 *
 * @list: first node in doubly linked list
 * @first: first node address
 * @second: second node address
 */
void nodes_swap(listint_t **list, listint_t *first, listint_t *second)
{
	if (!first->prev)	/* first node */
		*list = second;
	else
		first->prev->next = second;

	second->prev = first->prev;

	if (second->next)	/* last node */
		second->next->prev = first;


	first->prev = second;
	first->next = second->next;
	second->next = first;
}

/**
 * cocktail_sort_list - cocktail sort algorithm
 * to sort numbers
 *
 * @list: first node of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *future;
	int changed = 1;

	if (!list || !(*list) || !(*list)->next)  /* one node */
		return;

	future = *list;
	while (changed)
	{
		changed = 0;
		while (future->next)    /* move forward */
		{
			if (future->n > future->next->n)
			{
				nodes_swap(list, future, future->next);
				print_list(*list);
				changed = 1;
				continue;
			}
			future = future->next;
		}

		if (!changed)
			break;

		changed = 0;
		while (future->prev)    /* move backwards */
		{
			if (future->n < future->prev->n)
			{
				nodes_swap(list, future->prev, future);
				print_list(*list);
				changed = 1;
				continue;
			}
			future = future->prev;
		}
	}
}
