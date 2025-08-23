#!/usr/bin/python3
"""
Prime Game: determine the overall winner across multiple rounds.

Maria and Ben pick primes in turns from 1..n, removing each chosen prime
and its multiples. The player unable to move loses the round.
Return the name of the player who wins the most rounds, or None on tie.
"""


def isWinner(x, nums):
    """
    Determine who wins the most rounds of the prime game.

    Args:
        x (int): number of rounds (use up to the first x values in nums)
        nums (list): list of n values for each round

    Returns:
        str or None: "Maria" or "Ben" if a clear winner exists, else None
    """
    if not isinstance(x, int) or x <= 0:
        return None
    if not nums or not isinstance(nums, list):
        return None

    rounds = nums[:x]
    max_n = 0
    for n in rounds:
        if isinstance(n, int) and n > max_n:
            max_n = n

    if max_n < 2:
        # No primes in any round; Ben wins all by default, but if x==0 or list
        # empty we returned above. Here, check actual counts.
        maria_wins = 0
        ben_wins = 0
        for n in rounds:
            if n >= 2:
                # This won't happen due to max_n < 2; included for clarity
                maria_wins += 1
            else:
                ben_wins += 1
        if maria_wins > ben_wins:
            return "Maria"
        if ben_wins > maria_wins:
            return "Ben"
        return None

    # Sieve of Eratosthenes up to max_n
    primes = [False, False] + [True] * (max_n - 1)  # index 0..max_n
    p = 2
    while p * p <= max_n:
        if primes[p]:
            step = p
            start = p * p
            while start <= max_n:
                primes[start] = False
                start += step
        p += 1

    # prefix count of primes: prime_count[i] = #primes in [0..i]
    prime_count = [0] * (max_n + 1)
    running = 0
    for i in range(max_n + 1):
        if primes[i]:
            running += 1
        prime_count[i] = running

    maria_wins = 0
    ben_wins = 0

    for n in rounds:
        if not isinstance(n, int) or n < 1:
            # Invalid or trivial round (no primes), Ben wins by default
            ben_wins += 1
            continue
        # If the number of primes up to n is odd, Maria wins; else Ben wins.
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
    