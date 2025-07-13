#!/usr/bin/python3
"""
Island Perimeter Module
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of an island in a grid.

    Args:
        grid: List of list of integers where 0 = water, 1 = land

    Returns:
        Integer representing the perimeter of the island
    """
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # Land cell
                # Check all 4 directions
                # Top
                if i == 0 or grid[i-1][j] == 0:
                    perimeter += 1
                # Bottom
                if i == rows-1 or grid[i+1][j] == 0:
                    perimeter += 1
                # Left
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1
                # Right
                if j == cols-1 or grid[i][j+1] == 0:
                    perimeter += 1

    return perimeter
