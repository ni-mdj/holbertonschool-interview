#!/usr/bin/python3
"""
Rain calculation module.

This module contains a function to calculate the amount of rainwater
retained after it rains on a series of walls.
"""


def rain(walls):
    """
    Calculate the amount of rainwater retained between walls.

    Given a list of non-negative integers representing the heights of walls
    with unit width 1, calculate how many square units of water will be
    retained after it rains.

    Args:
        walls: A list of non-negative integers representing wall heights.

    Returns:
        An integer indicating the total amount of rainwater retained.
        Returns 0 if the list is empty.

    The algorithm works by:
    1. For each position, find the maximum height to the left
    2. For each position, find the maximum height to the right
    3. The water retained at each position is the minimum of the two maxima
       minus the wall height at that position
    """
    if not walls or len(walls) == 0:
        return 0

    n = len(walls)
    if n < 3:
        return 0

    # Calculate maximum height to the left of each position
    left_max = [0] * n
    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    # Calculate maximum height to the right of each position
    right_max = [0] * n
    right_max[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    # Calculate trapped water
    water = 0
    for i in range(n):
        water_level = min(left_max[i], right_max[i])
        water += max(0, water_level - walls[i])

    return water
