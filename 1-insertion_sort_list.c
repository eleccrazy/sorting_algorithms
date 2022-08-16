#include "sort.h"
#include <stdio.h>

/**
 * swapper - Swappes two nodes from a doubly linked list.
 *
 * @list: A pointer to a pointer that points to the head of  the list.
 * @previous: A pointer to a pointer that points to the first node to be
 * swapped.
 * @traverse: A pointer to the next node to be swapped.
 *
 */


void swapper(listint_t **list, listint_t *traverse, listint_t **previous)
{
	(*previous)->next = traverse->next;

	if (traverse->next)
		traverse->next->prev = *previous;

	traverse->prev = (*previous)->prev;
	traverse->next = *previous;

	if ((*previous)->prev)
		(*previous)->prev->next = traverse;
	else
		*list = traverse;

	(*previous)->prev = traverse;
	*previous = traverse->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer that points to another pointer which
 * inturn points to the head of the list.
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *traverse, *previous;

	if (!list || !(*list) || !(*list)->next)
		return;

	traverse = (*list)->next;

	while (traverse)
	{
		temp = traverse->next;
		previous = traverse->prev;

		while (previous && traverse->n < previous->n)
		{
			swapper(list, traverse, &previous);
			print_list((const listint_t *)*list);
		}

		traverse = temp;
	}
}
