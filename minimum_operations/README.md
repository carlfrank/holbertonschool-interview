This task involves determining the minimum number of operations needed to produce exactly n H characters in a text file, starting with just one H. You are only allowed to perform two operations:

    Copy All: Copies all the current H characters to memory.
    Paste: Pastes the characters in memory into the file.

The key idea is to use factorization to solve this problem. Every time you find a factor of n, it represents the operations required to replicate the characters.
Approach:

    Start with n and initialize the operation count to 0.
    For each number starting from 2 (the smallest factor):
        If the number divides n, add it to the operations count and divide n by that factor.
        Repeat until n becomes 1.
    If n is less than 2, return 0 because it's impossible to create fewer than two H's.

Example:
Input: n = 9

    Factors: 3 × 3
    Operations:
        Copy All (1 operation), Paste (1 operation) -> 2 H's.
        Paste again (1 operation) -> 3 H's.
        Copy All (1 operation), Paste (1 operation), Paste again (1 operation) -> 9 H's.
    Total Operations = 6.

Input: n = 12

    Factors: 2 × 2 × 3
    Operations:
        Copy All, Paste -> 2 H's.
        Copy All, Paste -> 4 H's.
        Copy All, Paste, Paste, Paste -> 12 H's.
    Total Operations = 7.

By breaking n into factors, you minimize redundant operations and achieve the target efficiently.