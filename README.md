# Holberton School - Interview Preparation

![Holberton School](https://www.holbertonschool.com/holberton-school-logo.png)

## About this Repository

This repository contains solutions to Holberton School interview preparation problems. These problems test algorithmic thinking, problem-solving skills, and coding proficiency across different programming languages (Python, C).

## Projects Overview

### 1. [Minimum Operations](./minimum_operations)
**Language:** Python  
**Difficulty:** Easy  
**Weight:** 1  

Calculate the fewest number of operations needed to result in exactly n H characters in a file using only Copy All and Paste operations. The solution uses prime factorization.

**Key Concepts:** Prime factorization, greedy algorithms

---

### 2. [Sandpiles](./sandpiles)
**Language:** C  
**Difficulty:** Intermediate  
**Weight:** 1  

Implement the sandpiles mathematical model. Compute the sum of two sandpiles and apply toppling rules until stability is achieved. A sandpile is stable when no cell contains more than 3 grains.

**Key Concepts:** 2D arrays, cellular automata, stability conditions

---

### 3. [Heap Insert](./heap_insert)
**Language:** C  
**Difficulty:** Intermediate  

Implement binary tree operations and heap insertion. Build and manipulate binary tree structures with proper parent-child relationships.

**Key Concepts:** Binary trees, heaps, tree traversal

---

### 4. [Insert in Sorted Linked List](./insert_in_sorted_linked_list)
**Language:** C  
**Difficulty:** Easy  

Insert a node in a sorted singly linked list while maintaining the sorted order. Handle all edge cases including empty lists and boundary insertions.

**Key Concepts:** Linked lists, pointers, sorting

---

### 5. [Lockboxes](./lockboxes)
**Language:** Python  
**Difficulty:** Easy  

Determine if all locked boxes can be opened. A box can be opened if you have its key, and opening a box reveals keys to other boxes.

**Key Concepts:** Graph theory, DFS, BFS

---

### 6. [Linked List Palindrome](./linked_list_palindrome)
**Language:** C  
**Difficulty:** Novice  
**Weight:** 1  

Check if a singly linked list is a palindrome. Implement an efficient algorithm using the two-pointer technique to find the middle and reverse the second half.

**Key Concepts:** Linked lists, two-pointer technique, list reversal

---

## Project Structure

```
holbertonschool-interview/
├── README.md                          # This file
├── minimum_operations/
│   ├── 0-minoperations.py            # Main solution
│   ├── 0-main.py                     # Test file
│   └── README.md                     # Detailed documentation
├── sandpiles/
│   ├── 0-sandpiles.c                 # Main solution
│   ├── sandpiles.h                   # Header file
│   └── README.md                     # Detailed documentation
├── heap_insert/
│   ├── 0-binary_tree_node.c          # Binary tree node creation
│   ├── 1-heap_insert.c               # Heap insertion
│   ├── binary_trees.h                # Header file
│   └── README.md                     # Detailed documentation
├── insert_in_sorted_linked_list/
│   ├── 0-insert_number.c             # Linked list insertion
│   ├── lists.h                       # Header file
│   └── README.md                     # Detailed documentation
├── lockboxes/
│   ├── 0-lockboxes.py                # Main solution
│   └── README.md                     # Detailed documentation
└── linked_list_palindrome/
    ├── 0-is_palindrome.c             # Palindrome checking function
    ├── linked_lists.c                # Helper functions
    ├── lists.h                       # Header file
    ├── 0-main.c                      # Test file
    └── README.md                     # Detailed documentation
```

## How to Use This Repository

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ni-mdj/holbertonschool-interview.git
   cd holbertonschool-interview
   ```

2. **Navigate to a specific project:**
   ```bash
   cd minimum_operations
   ```

3. **Read the README in each project folder** for detailed explanations, examples, and compilation/execution instructions.

4. **Test the solutions:**
   - **Python projects:** `python3 0-main.py`
   - **C projects:** `gcc -Wall -Wextra -Werror -pedantic [files] -o [output]`

## Requirements

- **Python:** Version 3.4.3 or higher (for Python projects)
- **C Compiler:** gcc 4.8.4 or higher with flags `-Wall -Wextra -Werror -pedantic`
- **Editor:** vi, vim, or emacs
- **OS:** Ubuntu 14.04 LTS or compatible

## Code Standards

All projects follow strict coding standards:

- **Python:** PEP 8 style guide (version 1.7.x)
- **C:** Betty style guide
- All files end with a newline
- All executable files have proper shebangs (`#!/usr/bin/python3` or similar)
- Comprehensive code documentation and comments
- No global variables (where applicable)
- Proper function prototypes in header files

## Author

**Name:** Médie Noé  
**GitHub:** [ni-mdj](https://github.com/ni-mdj)  
**School:** Holberton School

## Learning Resources

- [Prime Factorization](https://en.wikipedia.org/wiki/Prime_factor)
- [Sandpiles - Numberphile](https://www.youtube.com/watch?v=1MtEUErz7Gg)
- [Binary Trees](https://en.wikipedia.org/wiki/Binary_tree)
- [Linked Lists](https://en.wikipedia.org/wiki/Linked_list)
- [Graph Theory](https://en.wikipedia.org/wiki/Graph_theory)
- [PEP 8 Style Guide](https://www.python.org/dev/peps/pep-0008/)
- [Betty Style Guide](https://github.com/holbertonschool/Betty)

## License

This project is part of Holberton School's curriculum. All rights reserved.

## Acknowledgments

- Holberton School for the problem statements and guidance
- Contributors and mentors who provided feedback and support