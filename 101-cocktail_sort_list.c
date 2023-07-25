#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 * @list: Pointer to the head of the list
 */
void swap_nodes(listint_t **a, listint_t **b, listint_t **list)
{
    listint_t *tmp_prev_a = (*a)->prev;
    listint_t *tmp_next_a = (*a)->next;
    listint_t *tmp_prev_b = (*b)->prev;
    listint_t *tmp_next_b = (*b)->next;

    if (tmp_prev_a)
        tmp_prev_a->next = *b;
    if (tmp_next_a)
        tmp_next_a->prev = *b;
    if (tmp_prev_b)
        tmp_prev_b->next = *a;
    if (tmp_next_b)
        tmp_next_b->prev = *a;

    (*a)->prev = tmp_prev_b;
    (*a)->next = tmp_next_b;
    (*b)->prev = tmp_prev_a;
    (*b)->next = tmp_next_a;

    if (*a == *list)
        *list = *b;
    else if (*b == *list)
        *list = *a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail Shaker sort algorithm
 *
 * @list: The doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = NULL;
    listint_t *end = NULL;
    listint_t *current = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        for (current = start = *list; current->next != end; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(&current, &(current->next), list);
                swapped = 1;
                if (current->prev == NULL)
                    start = current;
                print_list(*list);
            }
        }
        if (!swapped)
            break;

        swapped = 0;
        end = current;
        for (current = end->prev; current != start; current = current->prev)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(&current, &(current->next), list);
                swapped = 1;
                if (current->prev == NULL)
                    start = current;
                print_list(*list);
            }
        }
    }
}

