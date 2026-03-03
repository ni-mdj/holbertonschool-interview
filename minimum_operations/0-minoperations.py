#!/usr/bin/python3
"""
Minimum Operations module

Calculates the fewest number of operations needed to result
in exactly n H characters in a file using Copy All and Paste operations.
"""


def minOperations(n):
    """
    Calculate the fewest number of operations needed to reach n H characters.

    Starting with a single H, using Copy All and Paste operations,
    determine the minimum number of operations to reach exactly n H's.

    Args:
        n: The target number of H characters (integer)

    Returns:
        The minimum number of operations needed, or 0 if impossible

    The key insight is that the minimum operations equals the sum of
    the prime factors of n. For example:
    - n=4: factors are [2,2], so 2+2=4 operations
    - n=12: factors are [2,2,3], so 2+2+3=7 operations
    """

    if n < 2:
        return 0

    operations = 0
    factor = 2

    # Find all prime factors and sum them
    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
