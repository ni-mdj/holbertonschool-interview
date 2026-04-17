#include <stdlib.h>

#include "binary_trees.h"

/**
 * free_avl - frees an AVL tree
 * @tree: pointer to tree root
 */
static void free_avl(avl_t *tree)
{
	if (tree == NULL)
		return;

	free_avl(tree->left);
	free_avl(tree->right);
	free(tree);
}

/**
 * build_avl - builds an AVL tree from a sorted array slice
 * @array: pointer to first element in slice
 * @size: number of elements in slice
 * @parent: parent node of the subtree root
 *
 * Return: pointer to subtree root, or NULL on failure
 */
static avl_t *build_avl(int *array, size_t size, avl_t *parent)
{
	size_t mid;
	size_t right_size;
	avl_t *root;

	if (size == 0)
		return (NULL);

	mid = (size - 1) / 2;
	right_size = size - mid - 1;

	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);

	root->n = array[mid];
	root->parent = parent;
	root->left = build_avl(array, mid, root);
	if (mid != 0 && root->left == NULL)
	{
		free(root);
		return (NULL);
	}

	root->right = build_avl(array + mid + 1, right_size, root);
	if (right_size != 0 && root->right == NULL)
	{
		free_avl(root->left);
		free(root);
		return (NULL);
	}

	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to first element of the array
 * @size: number of elements in @array
 *
 * Return: pointer to the root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl(array, size, NULL));
}
