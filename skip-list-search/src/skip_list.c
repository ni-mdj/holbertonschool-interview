#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * create_skiplist - Creates a skip list from an array
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: Pointer to the head of the skip list
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list, *node, *express_node;
	size_t i, express_index;

	if (array == NULL || size == 0)
		return (NULL);

	list = NULL;
	express_node = NULL;
	express_index = (size_t)sqrt((double)size);

	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(skiplist_t));
		if (node == NULL)
			return (NULL);

		node->n = array[i];
		node->index = i;
		node->next = NULL;
		node->express = NULL;

		if (list == NULL)
		{
			list = node;
		}
		else
		{
			skiplist_t *temp = list;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = node;
		}

		if (i % express_index == 0)
		{
			if (express_node != NULL)
				express_node->express = node;
			express_node = node;
		}
	}

	return (list);
}

/**
 * print_skiplist - Prints the skip list
 * @list: Pointer to the head of the skip list
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *node;

	printf("List :\n");
	for (node = list; node != NULL; node = node->next)
		printf("Index[%lu] = [%d]\n", node->index, node->n);

	printf("\nExpress lane :\n");
	for (node = list; node != NULL; node = node->express)
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	printf("\n");
}

/**
 * free_skiplist - Frees the skip list
 * @list: Pointer to the head of the skip list
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *node;

	while (list != NULL)
	{
		node = list;
		list = list->next;
		free(node);
	}
}
