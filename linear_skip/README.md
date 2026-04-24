# Linear Skip

Implementation of a linear skip search algorithm in C.

## Description

A skip list is a data structure that allows O(log √n) search complexity within an ordered sequence of elements. It consists of a base list of elements with additional "express lanes" that allow faster traversal.

In this implementation:
- A node of the express lane is placed every √n nodes
- The express lane allows us to skip multiple nodes at a time
- When we find the range where the value might be, we switch to linear search

## Files

- `search.h` - Header file with `skiplist_t` structure definition and function prototypes
- `0-linear_skip.c` - Linear skip search function implementation

## Data Structure

```c
typedef struct skiplist_s
{
    int n;                      /* Integer value */
    size_t index;               /* Index of the node in the list */
    struct skiplist_s *next;    /* Pointer to the next node */
    struct skiplist_s *express; /* Pointer to the next node in the express lane */
} skiplist_t;
```

## Functions

### `skiplist_t *linear_skip(skiplist_t *head, int value)`

Searches for a value in a sorted skip list of integers.

**Parameters:**
- `head` - Pointer to the head of the skip list
- `value` - The value to search for

**Return:**
- Pointer to the first node where value is located
- NULL if value is not present or if head is NULL

**Behavior:**
- Prints each value checked during the search
- Displays "Value found between indexes [X] and [Y]" when the range is identified
- Returns the matching node or NULL

## Example

```c
#include "search.h"

int main(void)
{
    int array[] = {0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99};
    size_t size = sizeof(array) / sizeof(array[0]);
    
    skiplist_t *list = create_skiplist(array, size);
    skiplist_t *result = linear_skip(list, 53);
    
    if (result != NULL)
        printf("Found 53 at index: %lu\n", result->index);
    
    free_skiplist(list);
    return (EXIT_SUCCESS);
}
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-linear_skip.c skiplist/*.c -lm -o 0-linear_skip
```

## Usage

```bash
./0-linear_skip
```

## Example Output

```
List :
Index[0] = [0]
Index[1] = [1]
Index[2] = [2]
Index[3] = [3]
Index[4] = [4]
Index[5] = [7]
Index[6] = [12]
Index[7] = [15]
Index[8] = [18]
Index[9] = [19]
Index[10] = [23]
Index[11] = [53]
Index[12] = [61]
Index[13] = [62]
Index[14] = [76]
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

Value checked at index [4] = [4]
Value found between indexes [0] and [4]
Value checked at index [0] = [0]
Value checked at index [1] = [1]
Value checked at index [2] = [2]
Found 2 at index: 2

Value checked at index [4] = [4]
Value checked at index [8] = [18]
Value checked at index [12] = [61]
Value found between indexes [12] and [15]
Value checked at index [12] = [61]
Value checked at index [13] = [62]
Value checked at index [14] = [76]
Value checked at index [15] = [99]
Found 999 at index: (nil)
```

## Algorithm Complexity

- **Time Complexity**: O(√n) - We traverse at most √n nodes in the express lane and then at most √n nodes in the linear search
- **Space Complexity**: O(n) - We store all n nodes in the list

## Requirements

- Allowed editors: vi, vim, emacs
- All files will be compiled on Ubuntu 14.04 LTS
- Programs compiled with gcc 4.8.4 using flags: -Wall -Werror -Wextra -pedantic
- All files should end with a new line
- Code should use Betty style
- No global variables
- No more than 5 functions per file
- All header files should be include guarded

## Notes

The helper functions `create_skiplist`, `print_skiplist`, and `free_skiplist` are provided separately and not required to be submitted, but are used for testing purposes.
