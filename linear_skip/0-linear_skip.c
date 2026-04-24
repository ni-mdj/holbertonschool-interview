#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *linear;

	if (list == NULL)
		return (NULL);

	express = list;
	linear = list;

	while (express->express != NULL && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		linear = express;
		express = express->express;
	}

	printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);

	if (express->n == value)
		return (express);

	printf("Value found between indexes [%lu] and [%lu]\n",
		linear->index, express->index);

	linear = linear->next;

	while (linear != NULL && linear->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", linear->index, linear->n);
		linear = linear->next;
	}

	if (linear != NULL && linear->n == value)
		return (linear);

	return (NULL);
}
