#!/usr/bin/python3

"""
0-pascal_triangle module

This module contains a function to generate Pascal's triangle.
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers representing Pascal's
    triangle of n rows.

    Args:
        n (int): Number of rows in Pascal's triangle

    Returns:
        list: List of lists representing Pascal's triangle, empty if n <= 0
    """

    if n <= 0:
        return []

    triangle = []

    for i in range(n):
        # Each row starts and ends with 1
        row = [1]

        # For rows after the first, calculate middle values
        if i > 0:
            for j in range(1, i):
                # Each interior element is sum of two elements above it
                value = triangle[i-1][j-1] + triangle[i-1][j]
                row.append(value)

            # Add the ending 1 (except for the first row)
            row.append(1)

        triangle.append(row)

    return triangle
