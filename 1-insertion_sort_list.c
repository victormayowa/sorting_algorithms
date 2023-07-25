#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current)
	{
		listint_t *tmp = current->prev;

		while (tmp && current->n < tmp->n)
		{
			tmp->next = current->next;
			if (current->next)
				current->next->prev = tmp;
			current->next = tmp;
			current->prev = tmp->prev;
			tmp->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			tmp = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
