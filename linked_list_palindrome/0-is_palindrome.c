#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of the head of the linked list
 *
 * Description: A palindrome reads the same forwards and backwards.
 * Uses slow/fast pointer technique to find the middle of the list,
 * then reverses the second half and compares both halves.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *prev, *temp;

	if (head == NULL || *head == NULL)
		return (1);

	slow = *head;
	fast = *head;
	prev = NULL;

	/* Find middle of the list using slow/fast pointers */
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	/* Reverse the second half of the list */
	while (slow != NULL)
	{
		temp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = temp;
	}

	/* Compare first half with reversed second half */
	slow = *head;
	fast = prev;

	while (fast != NULL)
	{
		if (slow->n != fast->n)
			return (0);
		slow = slow->next;
		fast = fast->next;
	}

	return (1);
}

