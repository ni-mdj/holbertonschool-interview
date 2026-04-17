#!/usr/bin/python3

import sys


def print_solution(queens):
    """Print one solution in the expected format."""
    solution = []
    for row, col in enumerate(queens):
        solution.append([row, col])
    print(solution)


def solve_nqueens(n):
    """Backtracking solver for the N queens puzzle."""
    queens = [-1] * n
    used_cols = set()
    used_diag1 = set()  # row - col
    used_diag2 = set()  # row + col

    def backtrack(row):
        if row == n:
            print_solution(queens)
            return

        for col in range(n):
            diag1 = row - col
            diag2 = row + col

            if col in used_cols or diag1 in used_diag1 or diag2 in used_diag2:
                continue

            queens[row] = col
            used_cols.add(col)
            used_diag1.add(diag1)
            used_diag2.add(diag2)

            backtrack(row + 1)

            used_cols.remove(col)
            used_diag1.remove(diag1)
            used_diag2.remove(diag2)

    backtrack(0)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(n)
