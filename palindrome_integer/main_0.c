#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: always 0.
 */
int main(void)
{
	listint_t *head;

	head = NULL;
	add_nodeint_end(&head, 9);
	add_nodeint_end(&head, 9);
	add_nodeint_end(&head, 1);
	add_nodeint_end(&head, 9);
	add_nodeint_end(&head, 9);

	print_listint(head);

	if (is_palindrome(&head) == 1)
		printf("Linked list is a palindrome\n");
	else
		printf("Linked list is not a palindrome\n");

	free_listint(head);

	return (0);
}
