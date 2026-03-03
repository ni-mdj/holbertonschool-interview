#include "binary_trees.h"

/**
 * find_insert_parent - Trouve parent idéal pour l'insertion
 * @root: Pointeur vers la racine
 * Return: Le futur parent
 */
heap_t *find_insert_parent(heap_t *root)
{
	heap_t *queue[1024];
	int head = 0, tail = 0;

	queue[tail++] = root;
	while (head < tail)
	{
		heap_t *curr = queue[head++];

		if (!curr->left || !curr->right)
			return (curr);
		queue[tail++] = curr->left;
		queue[tail++] = curr->right;
	}
	return (NULL);
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine
 * @value: Valeur à insérer
 * Return: Pointeur vers le nouveau nœud
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;
	int tmp;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_insert_parent(*root);
	new = binary_tree_node(parent, value);

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->n;
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}
