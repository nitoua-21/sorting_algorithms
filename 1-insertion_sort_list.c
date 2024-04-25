#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
*
* @list: doubly linked list of integers
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current->next != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			tmp = current->prev;

			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev = tmp->prev;
			current->next = tmp;
			if (tmp->prev != NULL)
				tmp->prev->next = current;
			tmp->prev = current;
			if (tmp == *list)
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}

}
