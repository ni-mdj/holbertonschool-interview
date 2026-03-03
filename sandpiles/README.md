# Sandpiles

## Description
This project implements the sandpiles mathematical model. A sandpile is a 3x3 grid where each cell can contain grains of sand. The project implements a function that computes the sum of two sandpiles, applying the toppling rules to achieve a stable state.

## What is a Sandpile?
A sandpile is stable when no cell contains more than 3 grains of sand. When a cell exceeds 3 grains, it becomes unstable and "topples" - losing 4 grains and distributing 1 grain to each of its 4 neighbors (up, down, left, right). This process continues until the entire sandpile is stable.

## Algorithm
1. Add the values of grid2 to grid1
2. While grid1 is unstable:
   - Print the current unstable state
   - Topple all cells with more than 3 grains
   - Each toppling cell loses 4 grains and gives 1 to each neighbor

## Functions
- `sandpiles_sum(int grid1[3][3], int grid2[3][3])` - Main function that computes the sum and stabilizes grid1

## Example
```
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```

## Resources
- [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg)
