# Sandpiles

## Problem Statement

Write a function that computes the **sum of two sandpiles**.

**Prototype:**
```c
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

**Assumptions:**
- Both `grid1` and `grid2` are individually stable
- A sandpile is **stable** when none of its cells contains more than 3 grains
- After the function executes, `grid1` must be stable
- `grid1` must be printed before each toppling round, **only if it is unstable**
- You cannot allocate memory dynamically

---

## What is a Sandpile?

A sandpile is a 3×3 grid where each cell contains a non-negative number of grains. The sandpile operates under specific stability rules:

### Stability Condition
A sandpile is **stable** if and only if **every cell contains 3 or fewer grains**.

### Toppling Process
When a cell contains **more than 3 grains**, it becomes **unstable** and must "topple":
- The unstable cell **loses 4 grains**
- Each of its **4 neighbors** (up, down, left, right) receives **1 grain**

This process is called **toppling** and is repeated until the entire sandpile is stable.

---

## Algorithm

### Step 1: Add the Grids
```
grid1[i][j] += grid2[i][j]  for all i, j
```

### Step 2: Stabilize (Toppling Loop)
While the sandpile is unstable:
1. Print the current unstable grid
2. Print a separator (`=`)
3. Topple all unstable cells (cells with > 3 grains)
4. Check stability again

### Toppling Details
During each toppling round:
- Identify all cells with > 3 grains
- For each unstable cell:
  - Subtract 4 from the cell
  - Add 1 to each neighbor (if within bounds)

---

## Example Execution

### Input
```
grid1:          grid2:
3 3 3           1 3 1
3 3 3    +      3 3 3
3 3 3           1 3 1
```

### Step-by-step Output

```
Initial state (printed by main):
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1

After adding (grid1 = grid1 + grid2):
=
4 6 4
6 6 6
4 6 4

After first topple (cells [0][1], [1][0], [1][1], [1][2], [2][1] had > 3):
=
2 5 2
5 6 5
2 5 2

After second topple:
=
4 2 4
2 6 2
4 2 4

After third topple:
=
0 5 0
5 2 5
0 5 0

After fourth topple:
=
2 1 2
1 6 1
2 1 2

After fifth topple (now stable):
=
2 2 2
2 2 2
2 2 2

Final state (stable - no more printing)
```

---

## Implementation Details

### Helper Functions

1. **`is_stable(int grid[3][3])`**
   - Checks if all cells contain ≤ 3 grains
   - Returns 1 if stable, 0 if unstable

2. **`topple(int grid[3][3])`**
   - Performs one complete toppling round
   - All cells with > 3 grains topple simultaneously
   - Uses a temporary grid to avoid conflicts

3. **`print_grid(int grid[3][3])`**
   - Prints the 3×3 grid with proper formatting
   - Space-separated values, newline between rows

4. **`sandpiles_sum(int grid1[3][3], int grid2[3][3])`**
   - Main function that orchestrates the process
   - Adds grids, then stabilizes grid1

### Code Structure

```c
#include "sandpiles.h"

static void print_grid(int grid[3][3]) { /* ... */ }
static int is_stable(int grid[3][3]) { /* ... */ }
static void topple(int grid[3][3]) { /* ... */ }

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    // Add grids
    // Stabilize through toppling
}
```

---

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-sandpiles.c -o 0-sandpiles
```

### Compilation Flags Explained
- `-Wall` - Enable all common warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors
- `-pedantic` - Strict ANSI C compliance

---

## Testing

### Run with Test File 1
```bash
./0-sandpiles < test1.txt
```

### Run with Test File 2
```bash
./0-sandpiles < test2.txt
```

---

## Files in This Directory

| File | Purpose |
|---|---|
| `0-sandpiles.c` | Main solution with all functions |
| `sandpiles.h` | Header file with function prototype |
| `README.md` | This file |

---

## Requirements

- **Language:** C
- **Compiler:** gcc 4.8.4 or higher
- **Code Style:** Betty style guide
- **Header Guards:** `#ifndef`, `#define`, `#endif`
- **No Global Variables:** All state passed through function parameters
- **No Dynamic Memory:** No `malloc()` or `free()`
- **Maximum 5 Functions:** Per file limit
- **Documentation:** Proper comments and docstrings

---

## Key Concepts

- **Cellular Automata:** Discrete models of physical systems
- **Stability Conditions:** Mathematical constraints for valid states
- **Toppling Rules:** How unstable states transition to stable ones
- **2D Array Manipulation:** Working with grids and neighbors
- **Synchronous Updates:** All cells topple simultaneously in each round

---

## Additional Resources

- [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg) - Visual explanation
- [Sandpile Model - Wikipedia](https://en.wikipedia.org/wiki/Sandpile_model)
- [Cellular Automata](https://en.wikipedia.org/wiki/Cellular_automaton)
- [Betty Style Guide](https://github.com/holbertonschool/Betty)

---

## Author

**Médie Noé**  
Holberton School Interview Preparation
