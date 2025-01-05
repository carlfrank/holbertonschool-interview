#!/usr/bin/python3
"""
Module for the canUnlockAll method.
This module contains a function that determines if all boxes can be unlocked.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.

    Args:
        boxes (list of lists): A list where each element is
        a list containing keys to other boxes.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    if n == 0:
        return False

    # Keep track of which boxes we can unlock
    unlocked = [False] * n
    unlocked[0] = True  # First box is always unlocked

    # Keep track of keys we have found but haven't used yet
    keys_to_try = set(boxes[0])  # Start with keys from first box

    # Continue while we have keys to try and haven't unlocked all boxes
    while keys_to_try and False in unlocked:
        # Get a key from our set of keys
        current_key = keys_to_try.pop()

        # If this key opens a valid box we haven't opened yet
        if current_key < n and not unlocked[current_key]:
            # Mark the box as unlocked
            unlocked[current_key] = True
            # Add any new keys we found to our set
            for new_key in boxes[current_key]:
                if new_key < n and not unlocked[new_key]:
                    keys_to_try.add(new_key)

    # Return True if all boxes are unlocked
    return all(unlocked)
