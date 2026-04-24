# Linear Skip

Implementation of a linear skip search algorithm in C.

## Description

A skip list is a data structure that allows O(log √n) search complexity within an ordered sequence of elements. It consists of a base list of elements with additional "express lanes" that allow faster traversal.

In this implementation:
- A node of the express lane is placed every √n nodes
- The express lane allows us to skip multiple nodes at a time
- When we find the range where the value might be, we switch to linear search

## Project Structure

```
skip-list-search
├── src
│   ├── main.c          # Main function to test skip list implementation
│   ├── search.c        # Implementation of linear search in skip list
│   └── skip_list.c     # Functions for managing the skip list
├── include
│   └── search.h        # Header file for skip list structures and functions
├── Makefile            # Build instructions for the project
└── README.md           # Documentation for the project
```

## Compilation

```bash
make
```

Or compile manually:
```bash
gcc -Wall -Wextra -Werror -pedantic -lm -o linear_skip src/main.c src/search.c src/skip_list.c
```

## Running the Program

After compiling, you can run the program using:

```bash
./linear_skip
```

## Functions

- `create_skiplist(int *array, size_t size)` - Creates a skip list from an array of integers
- `print_skiplist(const skiplist_t *list)` - Prints the elements of the skip list and express lane
- `free_skiplist(skiplist_t *list)` - Frees the memory allocated for the skip list
- `linear_skip(skiplist_t *head, int value)` - Searches for a value in the skip list

## Example Output

```
List :
Index[0] = [0]
Index[1] = [1]
...
Index[15] = [99]

Express lane :
Index[0] = [0]
Index[4] = [4]
Index[8] = [18]
Index[12] = [61]

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [8] and [12]
Value checked at index [8] = [18]
Value checked at index [9] = [19]
Value checked at index [10] = [23]
Value checked at index [11] = [53]
Found 53 at index: 11
```

## Clean

```bash
make clean
```
