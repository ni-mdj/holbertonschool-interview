#include <stdlib.h>
#include "binary_trees.h"

/**
* tree_size - counts nodes
* @tree: root
* Return: size
*/
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
* get_parent - finds parent of insertion point
* @root: root
* @index: node index
* Return: parent node
*/
heap_t *get_parent(heap_t *root, size_t index)
{
	size_t mask = 1;

	while (mask <= index)
		mask <<= 1;
	mask >>= 2;

	while (mask > 1)
	{
		if (index & mask)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}

	return (root);
}

/**
* heapify_up - restore heap property
* @node: inserted node
* Return: final node position
*/
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
* heap_insert - inserts value into Max Heap
* @root: double pointer to root
* @value: value to insert
*
* Return: pointer to inserted node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *node;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root) + 1;
	parent = get_parent(*root, size);

	if (!(size & 1))
		node = parent->left = binary_tree_node(parent, value);
	else
		node = parent->right = binary_tree_node(parent, value);

	if (!node)
		return (NULL);

	return (heapify_up(node));
}
