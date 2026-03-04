#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: always 0.
 */
int main(void)
{
	unsigned long n;

	n = 12321;
	printf("%lu is a palindrome: %d\n", n, is_palindrome(n));
	n = 0;
	printf("%lu is a palindrome: %d\n", n, is_palindrome(n));
	n = 9;
	printf("%lu is a palindrome: %d\n", n, is_palindrome(n));
	n = 534322435;
	printf("%lu is a palindrome: %d\n", n, is_palindrome(n));
	return (0);
}
