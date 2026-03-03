#!/usr/bin/env bash

# Compile heap_insert
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-binary_tree_node.c 1-heap_insert.c binary_trees.c -o 0-binary_tree_node

# Compile linked list insert
cd ../insert_in_sorted_linked_list
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-insert_number.c -o 0-insert_number
