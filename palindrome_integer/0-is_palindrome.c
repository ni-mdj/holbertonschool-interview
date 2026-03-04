#include <stdio.h>

/**
 * is_palindrome - checks whether or not an unsigned integer is a palindrome
 * @n: unsigned integer to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed;
	unsigned long original;

	reversed = 0;
	original = n;

	while (n > 0)
	{
		reversed = (reversed * 10) + (n % 10);
		n /= 10;
	}

	return (reversed == original ? 1 : 0);
}
