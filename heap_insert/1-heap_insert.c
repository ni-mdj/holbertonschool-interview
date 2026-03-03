#include "binary_trees.h"

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap.
 * @root: Double pointeur vers la racine du tas.
 * @value: Valeur à stocker dans le nouveau nœud.
 *
 * Return: Pointeur vers le nœud inséré, ou NULL en cas d'échec.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int tmp;

	if (!root)
		return (NULL);

	/* 1. Si l'arbre est vide, on crée la racine */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* 2. Trouver le parent approprié pour maintenir l'arbre complet */
	parent = find_insert_parent(*root);
	new_node = binary_tree_node(parent, value);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* 3. "Percolate Up" : Remonter la valeur si elle est plus grande que le parent */
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * find_insert_parent - Trouve le parent où insérer le prochain nœud.
 * @root: Racine de l'arbre.
 *
 * Return: Pointeur vers le futur parent.
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
