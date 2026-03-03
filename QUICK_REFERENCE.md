# Quick Reference Guide

## 🚀 Quick Start

### Setup
```bash
cd /Users/no.med/holbertonschool-interview-1
```

### Run Python Tests
```bash
# Minimum Operations
python3 minimum_operations/0-main.py

# Lockboxes
python3 lockboxes/0-main.py
```

### Compile C Projects
```bash
# Heap Insert
cd heap_insert
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-binary_tree_node.c 1-heap_insert.c binary_trees.c -o heap_test
./heap_test

# Linked List Insert
cd ../insert_in_sorted_linked_list
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-insert_number.c -o list_test
./list_test

# Linked List Palindrome
cd ../linked_list_palindrome
gcc -Wall -Wextra -Werror -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
./palindrome
```

---

## 📌 Project Reference

| Project | Type | Complexity | Solution Approach |
|---------|------|-----------|------------------|
| Minimum Operations | Python | Easy | Prime Factorization |
| Sandpiles | C | Medium | 2D Array + Simulation |
| Heap Insert | C | Medium | Tree Data Structure |
| Insert in Sorted List | C | Easy | Linked List Manipulation |
| Lockboxes | Python | Easy | Graph Traversal (DFS/BFS) |
| Linked List Palindrome | C | Novice | Two-Pointer Technique |

---

## 🔍 Algorithm Complexity Summary

### Time Complexity
| Problem | Best | Average | Worst |
|---------|------|---------|-------|
| Minimum Operations | O(√n) | O(√n) | O(√n) |
| Sandpiles | O(n×m) | O(n×m×k) | O(n×m×k) |
| Heap Insert | O(log n) | O(log n) | O(log n) |
| Linked List Insert | O(1) | O(n) | O(n) |
| Lockboxes | O(n+e) | O(n+e) | O(n+e) |
| Linked List Palindrome | O(n) | O(n) | O(n) |

### Space Complexity
| Problem | Complexity |
|---------|-----------|
| Minimum Operations | O(1) |
| Sandpiles | O(1) |
| Heap Insert | O(n) |
| Linked List Insert | O(1) |
| Lockboxes | O(n) |
| Linked List Palindrome | O(1) |

---

## 📂 File Locations Quick Reference

```
minimum_operations/
├── 0-minoperations.py      # Main function
├── 0-main.py               # Test cases

sandpiles/
├── 0-sandpiles.c           # Main function
└── sandpiles.h             # Header

heap_insert/
├── 0-binary_tree_node.c    # Node creation
├── 1-heap_insert.c         # Insertion logic
├── binary_trees.h          # Definitions
└── 0-main.c                # Test

insert_in_sorted_linked_list/
├── 0-insert_number.c       # Main function
├── lists.h                 # Definitions
└── 0-main.c                # Test

lockboxes/
├── 0-lockboxes.py          # Main function
└── 0-main.py               # Test cases
```

---

## 💡 Key Function Signatures

### Python

```python
# Minimum Operations
def minOperations(n)
    # Returns: int (minimum operations or 0)

# Lockboxes
def canUnlockAll(boxes)
    # Returns: bool (True if all boxes can be opened)
```

### C

```c
// Heap Insert
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);

// Linked List Insert
listint_t *insert_node(listint_t **head, int number);

// Linked List Palindrome
int is_palindrome(listint_t **head);

// Sandpiles
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
```

---

## 🧪 Test Cases Quick Reference

### Minimum Operations
```python
minOperations(1)    # 0 - already have 1
minOperations(2)    # 2 - copy + paste
minOperations(4)    # 4 - [2, 2]
minOperations(12)   # 7 - [2, 2, 3]
```

### Lockboxes
```python
[[1], [2], [3], [4], []]     # True - all reachable
[[1, 2], [3], [4], []]       # False - box 2 unreachable
[]                            # False - empty
[[0]]                         # True - single box
```

### Linked List Insert
```
[1, 7, 9] + 5  → [1, 5, 7, 9]
[1, 7, 9] + 3  → [1, 3, 7, 9]
[1, 7, 9] + 10 → [1, 7, 9, 10]
```

---

## ⚠️ Common Pitfalls

1. **Minimum Operations:** Don't forget n=1 returns 0
2. **Sandpiles:** Print grid ONLY if unstable, separator placement matters
3. **Heap Insert:** Maintain complete binary tree + heap property
4. **Linked List:** Handle empty list and insertion at head
5. **Lockboxes:** Empty list returns False, not True

---

## 📖 Key Concepts

### Minimum Operations
- Prime Factorization
- Greedy Algorithm
- Trial Division

### Sandpiles
- Cellular Automata
- 2D Array Manipulation
- Stability Conditions

### Heap Insert
- Binary Tree Traversal
- Heap Property
- Complete Binary Tree
- Bubble Up (Heapify)

### Linked List Insert
- Pointer Manipulation
- List Traversal
- Sorted Insertion

### Lockboxes
- Graph Theory
- DFS/BFS Traversal
- Reachability Analysis
- Set Operations

---

## 🔗 Documentation Links

Each project has a comprehensive README.md in its directory containing:
- Full problem statement
- Algorithm explanation with examples
- Step-by-step execution
- Implementation details
- Time/space complexity analysis
- Additional resources

---

**Last Updated:** March 3, 2026
