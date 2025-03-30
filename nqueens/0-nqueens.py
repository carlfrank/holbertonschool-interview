#!/usr/bin/python3
"""
N Queens problem solver
"""
import sys


def is_safe(board, row, col, n):
    """
    Check if a queen can be placed at board[row][col]
    """
    # Check this row on left side
    for i in range(col):
        if board[row][i] == 1:
            return False

    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check lower diagonal on left side
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solve_nqueens(board, col, n, solutions):
    """
    Use backtracking to find all solutions
    """
    # Base case: If all queens are placed
    if col >= n:
        # Save the positions of queens
        solution = []
        for i in range(n):
            for j in range(n):
                if board[i][j] == 1:
                    solution.append([i, j])
        solutions.append(solution)
        return

    # Try placing queen in all rows of this column
    for i in range(n):
        if is_safe(board, i, col, n):
            # Place queen
            board[i][col] = 1

            # Recur to place rest of the queens
            solve_nqueens(board, col + 1, n, solutions)

            # Backtrack
            board[i][col] = 0


def print_solutions(n):
    """
    Main function to solve and print all solutions
    """
    # Create an empty n x n board
    board = [[0 for _ in range(n)] for _ in range(n)]

    # List to store solutions
    solutions = []

    # Solve the problem
    solve_nqueens(board, 0, n, solutions)

    # Print all solutions
    for solution in solutions:
        print(solution)


def main():
    """
    Main function to handle arguments and call solver
    """
    # Check number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Check if N is a number
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Check if N is at least 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Print solutions
    print_solutions(n)


if __name__ == "__main__":
    main()
