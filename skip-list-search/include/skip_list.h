#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <stdlib.h>

typedef struct skiplist_node {
    int value;
    struct skiplist_node **forward;
} skiplist_node_t;

typedef struct skiplist {
    int level;
    int size;
    skiplist_node_t *header;
} skiplist_t;

skiplist_t *create_skiplist(int max_level);
void print_skiplist(skiplist_t *list);
void free_skiplist(skiplist_t *list);

#endif /* SKIP_LIST_H */