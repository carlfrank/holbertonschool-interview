#!/usr/bin/python3
"""
0_main
Test script for the rain function
"""

rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))  # Expected output: 6

    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))  # Expected output: 6
    