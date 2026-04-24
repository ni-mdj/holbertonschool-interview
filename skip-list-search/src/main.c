#include <stdio.h>
#include "search.h"

int main(void)
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t size = sizeof(array) / sizeof(array[0]);
    skiplist_t *skiplist = create_skiplist(array, size);

    if (!skiplist)
    {
        fprintf(stderr, "Failed to create skip list\n");
        return 1;
    }

    print_skiplist(skiplist);

    int value_to_search = 5;
    skiplist_node_t *result = linear_skip(skiplist, value_to_search);

    if (result)
    {
        printf("Value %d found in the skip list\n", value_to_search);
    }
    else
    {
        printf("Value %d not found in the skip list\n", value_to_search);
    }

    free_skiplist(skiplist);
    return 0;
}