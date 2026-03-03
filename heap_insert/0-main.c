#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	heap_t *root = NULL;
	int values[] = {10, 5, 6, 2, 3, 7, 1, 4, 8, 40};
	int i, size = 10;

	printf("Inserting values: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", values[i]);
		heap_insert(&root, values[i]);
	}
	printf("\n\n");

	printf("Max Heap Structure:\n");
	binary_tree_print(root);

	return (EXIT_SUCCESS);
}
