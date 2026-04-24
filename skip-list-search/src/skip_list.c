#include <stdio.h>
#include <stdlib.h>
#include "skip_list.h"

/**
 * create_skiplist - Creates a new skip list.
 * @max_level: The maximum level for the skip list.
 * @p: The probability of promoting a node to the next level.
 * 
 * Return: A pointer to the newly created skip list.
 */
skiplist_t *create_skiplist(int max_level, float p) {
    skiplist_t *list = malloc(sizeof(skiplist_t));
    if (!list) return NULL;

    list->max_level = max_level;
    list->level = 0;
    list->header = malloc(sizeof(skiplist_node_t) * (max_level + 1));
    if (!list->header) {
        free(list);
        return NULL;
    }

    for (int i = 0; i <= max_level; i++) {
        list->header[i].value = 0;
        list->header[i].forward = NULL;
    }

    return list;
}

/**
 * print_skiplist - Prints the skip list.
 * @list: The skip list to print.
 */
void print_skiplist(skiplist_t *list) {
    skiplist_node_t *node;
    printf("Skip List:\n");
    for (int i = 0; i <= list->level; i++) {
        node = list->header[i].forward;
        printf("Level %d: ", i);
        while (node) {
            printf("%d ", node->value);
            node = node->forward;
        }
        printf("\n");
    }
}

/**
 * free_skiplist - Frees the skip list.
 * @list: The skip list to free.
 */
void free_skiplist(skiplist_t *list) {
    skiplist_node_t *node, *temp;
    for (int i = 0; i <= list->level; i++) {
        node = list->header[i].forward;
        while (node) {
            temp = node;
            node = node->forward;
            free(temp);
        }
    }
    free(list->header);
    free(list);
}