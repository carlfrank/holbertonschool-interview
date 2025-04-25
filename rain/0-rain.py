#!/usr/bin/python3
"""
0-rain
Calculates how many square units of water will be retained after it rains.
"""

def rain(walls):
    """
    Calculate total amount of rainwater retained.

    Args:
        walls (list): A list of non-negative integers representing wall heights.

    Returns:
        int: Total units of trapped rainwater.
    """
    if not walls or len(walls) < 3:
        return 0

    total = 0
    left = 0
    right = len(walls) - 1
    left_max = walls[left]
    right_max = walls[right]

    while left < right:
        if walls[left] < walls[right]:
            left += 1
            left_max = max(left_max, walls[left])
            total += max(0, left_max - walls[left])
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            total += max(0, right_max - walls[right])

    return total
    