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
        x (int): number of rounds
        nums (list): list of n values for each round

    Returns:
        str or None: "Maria" or "Ben" if a clear winner exists, else None
    """
    if not x or not nums:
        return None

    rounds = nums[:x]
    max_n = max(rounds) if rounds else 0

    # Build sieve up to max_n
    if max_n < 2:
        # No primes at all → Ben wins all playable rounds
        ben_wins = sum(1 for n in rounds if n <= 1)
        maria_wins = len(rounds) - ben_wins
        if maria_wins > ben_wins:
            return "Maria"
        if ben_wins > maria_wins:
            return "Ben"
        return None

    primes = [False, False] + [True] * (max_n - 1)
    p = 2
    while p * p <= max_n:
        if primes[p]:
            for m in range(p * p, max_n + 1, p):
                primes[m] = False
        p += 1

    # Prefix counts of primes
    prime_count = [0] * (max_n + 1)
    cnt = 0
    for i in range(max_n + 1):
        if primes[i]:
            cnt += 1
        prime_count[i] = cnt

    maria_wins = 0
    ben_wins = 0
    for n in rounds:
        # If number of primes ≤ n is odd → Maria wins; else Ben wins
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
