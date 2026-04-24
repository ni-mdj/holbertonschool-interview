#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the node where the value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list;
    skiplist_t *express;

    if (!list)
        return (NULL);

    while (current)
    {
        express = current->express;

        if (express)
            printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
        else
        {
            while (current)
            {
                printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
                if (current->n == value)
                    return (current);
                current = current->next;
            }
            return (NULL);
        }

        if (express->n >= value)
        {
            printf("Value found between indexes [%ld] and [%ld]\n", current->index, express->index);
            while (current && current->index <= express->index)
            {
                printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
                if (current->n == value)
                    return (current);
                current = current->next;
            }
            return (NULL);
        }
        current = express;
    }
    return (NULL);
}