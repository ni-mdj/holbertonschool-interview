#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Forward declaration */
typedef struct s_queue_node
{
	binary_tree_t *data;
	struct s_queue_node *next;
} s_queue_node;

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node
 *
 * Return: void
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char *prefix;
	int offset = 0;
	int is_left;
	s_queue_node *queue = NULL;
	s_queue_node *node;

	if (!tree)
		return;

	queue = malloc(sizeof(s_queue_node));
	if (!queue)
		return;

	queue->data = (binary_tree_t *)tree;
	queue->next = NULL;

	while (queue)
	{
		node = queue;
		queue = queue->next;

		if (node->data)
		{
			if (node->data->parent)
				is_left = (node->data == node->data->parent->left);
			else
				is_left = 0;

			prefix = "";
			if (node->data->parent)
				prefix = (is_left ? "`-- " : "|-- ");

			printf("%s%d\n", prefix, node->data->n);

			if (node->data->left || node->data->right)
			{
				if (node->data->left)
				{
					s_queue_node *left = malloc(sizeof(s_queue_node));
					if (left)
					{
						left->data = node->data->left;
						left->next = NULL;
						if (!queue)
							queue = left;
						else
						{
							s_queue_node *tmp = queue;
							while (tmp->next)
								tmp = tmp->next;
							tmp->next = left;
						}
					}
				}
				if (node->data->right)
				{
					s_queue_node *right = malloc(sizeof(s_queue_node));
					if (right)
					{
						right->data = node->data->right;
						right->next = NULL;
						if (!queue)
							queue = right;
						else
						{
							s_queue_node *tmp = queue;
							while (tmp->next)
								tmp = tmp->next;
							tmp->next = right;
						}
					}
				}
			}
		}
		free(node);
	}
}
