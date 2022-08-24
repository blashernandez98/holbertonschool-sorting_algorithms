#include "sort.h"

/**
 * swap - Swaps two nodes in a list.
 * @left: Node on the left.
 * @right: Node on the right.
 */

void swap(listint_t *left, listint_t *right)
{
	right->prev = left->prev;
	if (left->prev)
		(left->prev)->next = right;
	left->prev = right;
	left->next = right->next;
	if (right->next)
		(right->next)->prev = left;
	right->next = left;
}

/**
 * find_head - Finds head of a doubly linked list.
 * @node: Node in list.
 *
 * Return: First node of the list.
 */

listint_t *find_head(listint_t *node)
{
	while (node)
	{
		if (node->prev)
			node = node->prev;
		else
			break;
	}
	return (node);
}

/**
 * insertion_sort_list - Sorts list of integer using insertion sort algo.
 * @list: Doubly linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *cursor = NULL, *aux = NULL, *prev = NULL;

	if (list)
	{
		cursor = *list;
		while (cursor && cursor->next)
		{
			aux = cursor->next;
			if (cursor->n > aux->n)
			{
				swap(cursor, aux);
				*list = find_head(aux);
				print_list(*list);
				insertion_sort_list(list);
			}
			cursor = aux;
		}
	}
}
