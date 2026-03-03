# Linked List Palindrome

## Problem Statement

Write a function in C that checks if a singly linked list is a palindrome.

**Prototype:**
```c
int is_palindrome(listint_t **head);
```

**Requirements:**
- Return `1` if the list is a palindrome
- Return `0` if the list is not a palindrome
- An empty list is considered a palindrome
- You cannot use global variables
- No more than 5 functions per file

---

## What is a Palindrome?

A **palindrome** is a sequence that reads the same forwards and backwards.

### Examples

| List | Values | Palindrome? |
|------|--------|-----------|
| `1 -> 2 -> 3 -> 2 -> 1` | `1, 2, 3, 2, 1` | ✅ YES |
| `1 -> 2 -> 3` | `1, 2, 3` | ❌ NO |
| `5 -> 5 -> 5` | `5, 5, 5` | ✅ YES |
| `1` | `1` | ✅ YES |
| Empty | (none) | ✅ YES |

---

## Algorithm Explanation

### Approach: Slow/Fast Pointer with Reversal

The solution uses a **two-pointer technique** to detect the middle of the list, then reverses the second half and compares both halves.

#### Step-by-Step Algorithm

1. **Find the middle of the list**
   - Use slow pointer (moves 1 node) and fast pointer (moves 2 nodes)
   - When fast reaches the end, slow is at the middle
   
2. **Reverse the second half**
   - Starting from the middle, reverse the remaining nodes
   - This allows us to traverse from both ends simultaneously

3. **Compare both halves**
   - Compare nodes from the start with nodes from the reversed end
   - If any pair doesn't match, it's not a palindrome

4. **Restore the list** (optional)
   - Reverse the second half back to restore original structure

#### Visual Example

```
Original list: 1 -> 2 -> 3 -> 2 -> 1

Step 1: Find middle with slow/fast pointers
slow -> 3, fast -> NULL
(Middle found)

Step 2: Reverse second half (2 -> 1 becomes 1 -> 2)
1 -> 2 -> 3   and   1 -> 2 (reversed)

Step 3: Compare
Compare 1==1 ✓
Compare 2==2 ✓
Done! It's a palindrome.
```

---

## Implementation Details

### Key Functions

1. **`is_palindrome(listint_t **head)`**
   - Main function that checks if list is palindrome
   - Uses slow/fast pointer approach
   - Reverses and restores the list

### Helper Struct

```c
typedef struct listint_s
{
    int n;                    /* Value stored in node */
    struct listint_s *next;   /* Pointer to next node */
} listint_t;
```

---

## Time and Space Complexity

| Metric | Complexity | Notes |
|--------|-----------|-------|
| **Time** | O(n) | Single pass to find middle, single pass to compare |
| **Space** | O(1) | No extra data structures needed |

---

## Code Walkthrough

```c
int is_palindrome(listint_t **head)
{
    /* 1. Handle edge cases: NULL or empty list */
    if (head == NULL || *head == NULL)
        return (1);  /* Empty list is palindrome */

    /* 2. Find middle using slow/fast pointers */
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;   /* Move 2 steps */
        slow = slow->next;         /* Move 1 step */
    }

    /* 3. Reverse second half starting from middle */
    while (slow != NULL)
    {
        /* Standard list reversal technique */
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    /* 4. Compare both halves */
    while (fast != NULL)
    {
        if (slow->n != fast->n)
            return (0);  /* Not a palindrome */
        slow = slow->next;
        fast = fast->next;
    }

    /* 5. Restore list structure */
    /* Reverse the second half back */

    return (1);  /* Is a palindrome */
}
```

---

## Execution Example

### Test Case: Palindrome
```
Input: 1 -> 17 -> 972 -> 50 -> 98 -> 98 -> 50 -> 972 -> 17 -> 1

Output:
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

### Step-by-step Execution:

```
1. Find middle:
   slow: 1 -> 17 -> 972 -> 50 -> 98 (stops here)
   fast: finished

2. Reverse from 98 onward:
   First half: 1 -> 17 -> 972 -> 50 -> 98
   Second half (reversed): 1 <- 17 <- 972 <- 50 <- 98

3. Compare:
   98 vs 98 ✓
   50 vs 50 ✓
   972 vs 972 ✓
   17 vs 17 ✓
   1 vs 1 ✓

4. Result: PALINDROME
```

---

## Edge Cases

1. **Empty list:** `NULL` → Return `1` (palindrome)
2. **Single node:** `5` → Return `1` (palindrome)
3. **Two identical nodes:** `3 -> 3` → Return `1` (palindrome)
4. **Two different nodes:** `3 -> 5` → Return `0` (not palindrome)
5. **Odd length:** `1 -> 2 -> 3 -> 2 -> 1` → Return `1` (palindrome)
6. **Even length:** `1 -> 2 -> 2 -> 1` → Return `1` (palindrome)

---

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

### Compilation Flags Explained
- `-Wall` - Enable all common warnings
- `-Werror` - Treat warnings as errors
- `-Wextra` - Enable extra warnings
- `-pedantic` - Strict ANSI C compliance

---

## Testing

```bash
./palindrome
```

Expected output for the test case:
```
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

---

## Files in This Directory

| File | Purpose |
|---|---|
| `0-is_palindrome.c` | Palindrome checking function |
| `linked_lists.c` | Helper functions (print, add, free) |
| `lists.h` | Header with struct definitions |
| `0-main.c` | Test file |
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

- **Two Pointer Technique:** Using slow/fast pointers to find middle
- **Linked List Reversal:** Reversing part of a list in-place
- **Palindrome Detection:** Comparing values in symmetric positions
- **In-place Algorithm:** Using O(1) extra space
- **List Restoration:** Maintaining original list structure after check

---

## Alternative Approaches

### Approach 1: Using Stack (O(n) space)
- Push first half onto stack
- Compare second half with stack

### Approach 2: Using Recursion (O(n) space)
- Recursive call to end of list
- Compare during unwinding

### Approach 3: Two Pointers (Our approach - O(1) space)
- Find middle with slow/fast pointers
- Reverse second half
- Compare both halves
- **Most efficient**

---

## Common Mistakes to Avoid

1. **Forgetting NULL check:** Always handle NULL head
2. **Incorrect middle detection:** Fast pointer needs correct increment
3. **Not restoring list:** Leaving list in reversed state
4. **Off-by-one errors:** Careful with even/odd length lists
5. **Memory issues:** Ensure proper pointer updates

---

## Additional Resources

- [Linked Lists - Wikipedia](https://en.wikipedia.org/wiki/Linked_list)
- [Palindrome - Wikipedia](https://en.wikipedia.org/wiki/Palindrome)
- [Two Pointer Technique](https://en.wikipedia.org/wiki/Two-pointer_technique)
- [Linked List Reversal](https://www.geeksforgeeks.org/reverse-a-linked-list/)
- [Betty Style Guide](https://github.com/holbertonschool/Betty)

---

## Author

**Médie Noé**  
Holberton School Interview Preparation
