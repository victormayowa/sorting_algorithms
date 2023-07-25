#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **a, listint_t **b)
{
	listint_t *tmp_prev = (*a)->prev;
	listint_t *tmp_next = (*a)->next;

	if (tmp_prev)
		tmp_prev->next = *b;
	(*a)->next = (*b)->next;
	(*a)->prev = *b;
	if ((*a)->next)
		(*a)->next->prev = *a;
	(*b)->next = *a;
	(*b)->prev = tmp_prev;
	if (tmp_next)
		tmp_next->prev = *a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		tmp = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(&(current->prev), &current);
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		current = tmp;
	}
}
