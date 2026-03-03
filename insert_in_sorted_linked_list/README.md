# Insert in Sorted Linked List

## Problem Statement

Write a function that inserts a number into a sorted singly linked list.

**Prototype:**
```c
listint_t *insert_number(listint_t **head, int number);
```

**Requirements:**
- Maintain the sorted order of the list
- Return a pointer to the new node
- Handle all edge cases:
  - Empty list
  - Insertion at the beginning
  - Insertion in the middle
  - Insertion at the end
- The list remains sorted in ascending order after insertion

---

## What is a Linked List?

A **linked list** is a linear data structure consisting of nodes, where each node contains:
- **Data:** The value stored in the node
- **Next pointer:** A reference to the next node in the list (or NULL if it's the last node)

### Characteristics

- **Dynamic size:** Grows and shrinks as needed
- **No random access:** Must traverse from the beginning
- **Efficient insertion/deletion:** O(1) if position is known
- **Memory efficient:** Only stores what's needed

### Visual Representation

```
Empty list:  NULL

Single node: [5] -> NULL

Multiple nodes: [3] -> [7] -> [9] -> NULL
```

---

## Linked List Node Structure

```c
typedef struct listint_s
{
    int n;                          /* Integer value in the node */
    struct listint_s *next;         /* Pointer to the next node */
} listint_t;
```

---

## Algorithm

### Step 1: Check if List is Empty
If `*head == NULL`, the new node becomes the head.

### Step 2: Check if Insertion at Beginning
If `number < head->n`, insert before the current head.

### Step 3: Traverse the List
- Start from the head
- Move through the list while `current->next != NULL` and `number > current->next->n`

### Step 4: Insert the Node
- Create a new node with the given number
- Link the new node to the next node (`new->next = current->next`)
- Link the current node to the new node (`current->next = new`)

### Step 5: Return the New Node
Return a pointer to the newly inserted node.

---

## Insertion Cases

### Case 1: Empty List
```
Before: NULL

After inserting 5: [5] -> NULL
```

### Case 2: Insert at Beginning
```
Before: [7] -> [9] -> NULL

After inserting 3: [3] -> [7] -> [9] -> NULL
```

### Case 3: Insert in Middle
```
Before: [3] -> [7] -> [9] -> NULL

After inserting 5: [3] -> [5] -> [7] -> [9] -> NULL
```

### Case 4: Insert at End
```
Before: [3] -> [7] -> [9] -> NULL

After inserting 11: [3] -> [7] -> [9] -> [11] -> NULL
```

---

## Implementation Example

```c
listint_t *insert_number(listint_t **head, int number)
{
    listint_t *new, *current;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = number;
    new->next = NULL;

    // Case 1: Empty list or insert at beginning
    if (*head == NULL || number < (*head)->n)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    // Case 2: Find the correct position and insert
    current = *head;
    while (current->next != NULL && number > current->next->n)
        current = current->next;

    new->next = current->next;
    current->next = new;

    return (new);
}
```

---

## Step-by-Step Execution Example

**Task:** Insert 5 into `[3] -> [7] -> [9] -> NULL`

1. Create new node: `new->n = 5`, `new->next = NULL`
2. Check if empty: NO
3. Check if `5 < 3`: NO
4. Start traversal: `current = head (pointing to 3)`
5. Check condition: `3 != NULL && 5 > 7`? NO (loop doesn't execute)

Actually, let's fix that logic:

5. Check condition: `current->next != NULL && number > current->next->n`
   - `7 != NULL && 5 > 7`? NO (stop here)
6. Insert: 
   - `new->next = current->next` (new points to 7)
   - `current->next = new` (3 points to new)
7. Return `new`

**Result:** `[3] -> [5] -> [7] -> [9] -> NULL` ✓

---

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic [main].c 0-insert_number.c -o [output]
```

---

## Files in This Directory

| File | Purpose |
|---|---|
| `0-insert_number.c` | Main insertion function |
| `lists.h` | Header file with struct definition and prototype |
| `README.md` | This file |

---

## Requirements

- **Language:** C
- **Compiler:** gcc 4.8.4 or higher
- **Code Style:** Betty style guide
- **Header Guards:** Include guards in header file
- **No Global Variables:** All state passed through parameters
- **Documentation:** Proper comments and docstrings
- **Memory Management:** Proper allocation and handling

---

## Time and Space Complexity

| Operation | Time | Space |
|---|---|---|
| **Search** | O(n) | O(1) |
| **Insert** | O(n) | O(1) |
| **Delete** | O(n) | O(1) |
| **Access** | O(n) | O(1) |

---

## Key Concepts

- **Pointers:** Managing links between nodes
- **Memory Management:** Dynamic allocation with `malloc()`
- **Traversal:** Moving through the list to find insertion point
- **Sorting:** Maintaining ascending order
- **Edge Cases:** Handling empty list, beginning, end, and middle
- **Return Value:** Pointer to the newly created node

---

## Common Mistakes to Avoid

1. **Memory Leaks:** Always check `malloc()` return value
2. **NULL Pointer Dereference:** Verify pointers before using them
3. **Lost Pointers:** Store the new node before changing pointers
4. **Incorrect Insertion:** Verify the position maintains sorted order
5. **Head Update:** Don't forget to update `*head` when inserting at beginning
6. **Boundary Conditions:** Test empty list, single node, and multiple nodes

---

## Testing Strategy

```c
// Test 1: Insert into empty list
listint_t *head = NULL;
insert_number(&head, 5);  // head -> [5] -> NULL

// Test 2: Insert at beginning
head = NULL;
insert_number(&head, 5);
insert_number(&head, 3);  // head -> [3] -> [5] -> NULL

// Test 3: Insert in middle
head = NULL;
insert_number(&head, 9);
insert_number(&head, 5);
insert_number(&head, 7);  // head -> [5] -> [7] -> [9] -> NULL

// Test 4: Insert at end
insert_number(&head, 11);  // head -> [5] -> [7] -> [9] -> [11] -> NULL
```

---

## Additional Resources

- [Linked Lists - Wikipedia](https://en.wikipedia.org/wiki/Linked_list)
- [Singly Linked List](https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list)
- [Dynamic Memory Allocation in C](https://www.cprogramming.com/tutorial/dynamic_allocation.html)
- [Pointer Basics](https://www.cprogramming.com/tutorial/pointers.html)
- [Betty Style Guide](https://github.com/holbertonschool/Betty)

---

## Author

**Médie Noé**  
Holberton School Interview Preparation