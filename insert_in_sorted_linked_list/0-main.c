#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - Print linked list
 * @head: Head of the list
 */
void print_list(listint_t *head)
{
	while (head)
	{
		printf("%d", head->n);
		if (head->next)
			printf(" -> ");
		head = head->next;
	}
	printf("\n");
}

/**
 * free_list - Free linked list
 * @head: Head of the list
 */
void free_list(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	listint_t *head = NULL;
	int values[] = {1, 7, 9};
	int i, size = 3;

	printf("Creating sorted list: ");
	for (i = 0; i < size; i++)
	{
		insert_node(&head, values[i]);
		printf("%d ", values[i]);
	}
	printf("\n");

	printf("List: ");
	print_list(head);

	printf("\nInserting 5:\n");
	insert_node(&head, 5);
	printf("List: ");
	print_list(head);

	printf("Inserting 3:\n");
	insert_node(&head, 3);
	printf("List: ");
	print_list(head);

	printf("Inserting 10:\n");
	insert_node(&head, 10);
	printf("List: ");
	print_list(head);

	printf("Inserting 0:\n");
	insert_node(&head, 0);
	printf("List: ");
	print_list(head);

	free_list(head);
	return (EXIT_SUCCESS);
}
