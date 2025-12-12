#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 * @list: is the list to sort
 * Return: nothing
 */
insertion_sort_list(listint_t **list)
{
    listint_t *curr, *next, *prev;

	if ((!*list) || (!(*list)->next))
		return;

	curr = (*list)->next;
	while (curr)
	{
		next = curr->next;

		while (curr->prev != NULL && curr->prev->n > curr->n)
		{
			prev = curr->prev;
			if (curr->next != NULL)
				curr->next->prev = prev;

			prev->next = curr->next;
			curr->next = prev;
			curr->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = curr;

			prev->prev = curr;

			if (curr->prev == NULL)
				*list = curr;

			print_list(*list);
		}

		curr = next;
	}
}