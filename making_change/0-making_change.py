#!/usr/bin/python3
"""
Function to determine the minimum number of coins
needed to meet a given total.
"""


def makeChange(coins, total):
    """
    Returns the fewest number of coins needed to meet total.
    If total is 0 or less, returns 0.
    If total cannot be met by any number of coins, returns -1.
    """
    if total <= 0:
        return 0

    # Initialize an array for storing minimum coins for each amount
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
