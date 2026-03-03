# Heap Insert

## Problem Statement

Implement functions to work with binary trees and heaps:

1. **`binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)`**
   - Creates a new binary tree node
   - Sets the value and parent
   - Initializes left and right children to NULL

2. **`int heap_insert(heap_t **root, int value)`**
   - Inserts a new value into a max binary heap
   - Maintains the complete binary tree property
   - Maintains the heap property (parent ≥ children)
   - Returns the address of the new node, or NULL if failure

---

## What is a Binary Tree?

A **binary tree** is a tree data structure where each node has at most two children, referred to as the **left child** and the **right child**.

### Key Properties

- **Root:** The topmost node (no parent)
- **Parent:** A node that has one or more children
- **Leaf:** A node with no children
- **Height:** The maximum distance from root to any leaf
- **Depth:** The distance from root to a specific node

---

## What is a Heap?

A **heap** is a specialized tree-based data structure that satisfies the **heap property**:

### Max Heap
- Each parent node is **greater than or equal to** its children
- The largest element is always at the root

### Min Heap
- Each parent node is **less than or equal to** its children
- The smallest element is always at the root

### Complete Binary Tree Property
A binary tree is **complete** if:
- All levels are fully filled except possibly the last
- The last level is filled from left to right

---

## Binary Tree Node Structure

```c
typedef struct binary_tree_s
{
    int n;                          /* Integer value stored in the node */
    struct binary_tree_s *parent;   /* Pointer to parent node */
    struct binary_tree_s *left;     /* Pointer to left child */
    struct binary_tree_s *right;    /* Pointer to right child */
} binary_tree_t;

typedef binary_tree_t heap_t;       /* Heap type alias */
```

---

## Implementation Details

### Part 0: Create a Binary Tree Node

**Function:** `binary_tree_node()`

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // 1. Allocate memory for new node
    // 2. Set the value
    // 3. Set the parent
    // 4. Initialize left and right to NULL
    // 5. Return the new node
}
```

**Steps:**
1. Use `malloc()` to allocate memory for a `binary_tree_t` struct
2. Set `node->n = value`
3. Set `node->parent = parent`
4. Set `node->left = NULL` and `node->right = NULL`
5. Return the allocated node

### Part 1: Insert into a Heap

**Function:** `heap_insert()`

```c
int heap_insert(heap_t **root, int value)
{
    // 1. Create a new node with the value
    // 2. Find the correct insertion position (complete tree property)
    // 3. Insert the new node
    // 4. Bubble up to maintain heap property
    // 5. Update root if necessary
    // 6. Return the address of the new node
}
```

**Algorithm:**
1. Create new node using `binary_tree_node()`
2. If tree is empty, new node becomes root
3. Otherwise:
   - Find the leftmost position in the last level (using level order traversal)
   - Insert the new node there
   - Compare with parent; if larger (for max heap), swap values
   - Continue bubbling up until heap property is satisfied

---

## Tree Traversals

### Level Order (Breadth-First Search)
Visit nodes level by level, left to right:
```
       1
      / \
     2   3
    / \ /
   4  5 6

Order: 1, 2, 3, 4, 5, 6
```

### In-Order (Left-Root-Right)
```
Order: 4, 2, 5, 1, 3, 6
```

### Pre-Order (Root-Left-Right)
```
Order: 1, 2, 4, 5, 3, 6
```

### Post-Order (Left-Right-Root)
```
Order: 4, 5, 2, 6, 3, 1
```

---

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic [main].c 0-binary_tree_node.c 1-heap_insert.c -o [output]
```

---

## Files in This Directory

| File | Purpose |
|---|---|
| `0-binary_tree_node.c` | Node creation function |
| `1-heap_insert.c` | Heap insertion function |
| `binary_trees.h` | Header file with struct definitions and prototypes |
| `README.md` | This file |

---

## Requirements

- **Language:** C
- **Compiler:** gcc 4.8.4 or higher
- **Code Style:** Betty style guide
- **Header Guards:** Include guards in header file
- **No Global Variables:** All state passed through parameters
- **Function Limit:** Maximum 5 functions per file
- **Documentation:** Proper comments and docstrings

---

## Key Concepts

- **Tree Structures:** Hierarchical data organization
- **Pointers:** Managing parent-child relationships
- **Memory Management:** Dynamic allocation with `malloc()`
- **Heap Property:** Ordering constraint for efficient operations
- **Complete Binary Trees:** Filling pattern for heaps
- **Bubble Up (Heapify):** Restoring heap property after insertion

---

## Common Mistakes to Avoid

1. **Memory Leaks:** Always free allocated memory when done
2. **NULL Pointers:** Check for NULL before dereferencing
3. **Incorrect Parent Assignment:** Parent pointer must point to actual parent
4. **Violating Complete Tree Property:** Insertion must maintain left-to-right filling
5. **Bubble Up Logic:** Must continue until heap property is satisfied

---

## Additional Resources

- [Binary Trees - Wikipedia](https://en.wikipedia.org/wiki/Binary_tree)
- [Heaps - Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)
- [Tree Traversals](https://en.wikipedia.org/wiki/Tree_traversal)
- [Complete Binary Tree](https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)
- [Betty Style Guide](https://github.com/holbertonschool/Betty)

---

## Author

**Médie Noé**  
Holberton School Interview Preparation