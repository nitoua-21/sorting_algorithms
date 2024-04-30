#include "sort.h"

/**
 * Swap two adjacent nodes in a doubly linked list, ensuring list integrity.
 * Also updates the head of the list if necessary.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
    if (a == NULL || b == NULL)
        return;

    if (a->prev)
        a->prev->next = b;
    if (b->next)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;

    b->next = a;
    a->prev = b;

    if (b->prev == NULL)
        *list = b;
}

/**
 * Sorts a doubly linked list of integers in ascending order using the
 * Cocktail shaker sort algorithm.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start, *end, *curr;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    start = *list;
    end = NULL;

    while (swapped)
    {
        swapped = 0;
        for (curr = start; curr->next != end; curr = curr->next)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(list, curr, curr->next);
                swapped = 1;
                print_list(*list);
                curr = curr->prev;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end = curr;

        while (curr->prev && curr != start)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(list, curr->prev, curr);
                swapped = 1;
                print_list(*list);
                curr = curr->next;
            }
            curr = curr->prev;
        }

        start = *list;
    }
}
