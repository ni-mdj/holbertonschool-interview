# Lockboxes

## Problem Statement

You have `n` number of locked boxes in front of you. Each box is numbered sequentially from `0` to `n - 1` and each box may contain keys to the other boxes.

**Write a method that determines if all of the boxes can be opened.**

**Assumptions:**
- A key with the same number as a box opens that box
- You can assume all keys will be positive integers
- There can be keys and boxes with the same number (a key to box 1 is in box 1)
- You may assume the first box (box 0) is unlocked

**Prototype:**
```python
def canUnlockAll(boxes)
```

**Return:**
- `True` if all boxes can be opened
- `False` otherwise

### Example

```python
boxes = [[1], [2], [3], [4], []]

# Starting with box 0 (unlocked)
# Box 0 contains key to box 1 -> unlock box 1
# Box 1 contains key to box 2 -> unlock box 2
# Box 2 contains key to box 3 -> unlock box 3
# Box 3 contains key to box 4 -> unlock box 4
# All boxes unlocked: True
```

---

## Problem Analysis

This is a **graph traversal problem** where:
- Each box is a **node**
- A key in box A pointing to box B is a **directed edge** from A to B
- We need to determine if all nodes are **reachable** from node 0

### Graph Interpretation

```
boxes = [[1], [2], [3], [4], []]

Graph:
0 -> 1 -> 2 -> 3 -> 4

All nodes reachable from 0: True
```

### Another Example

```
boxes = [[1, 2], [3], [4], []]

Graph:
    ┌--2--┐
    v     v
0 --1---> 3
    └----> 4 (unreachable from the above paths)

All nodes reachable from 0: False (box 4 cannot be opened)
```

---

## Algorithm Solutions

### Solution 1: Depth-First Search (DFS)

**Approach:** Use a stack-based DFS to traverse all reachable boxes.

```python
def canUnlockAll(boxes):
    """
    Use DFS with a stack to explore all reachable boxes.
    """
    if not boxes:
        return True
    
    visited = set()
    stack = [0]  # Start with box 0 (unlocked)
    
    while stack:
        box = stack.pop()
        
        if box in visited:
            continue
        
        visited.add(box)
        
        # Add all keys in current box to stack
        for key in boxes[box]:
            if key not in visited and key < len(boxes):
                stack.append(key)
    
    # Check if all boxes were visited
    return len(visited) == len(boxes)
```

**Time Complexity:** O(n + e) where n = number of boxes, e = total keys  
**Space Complexity:** O(n) for the visited set and stack

### Solution 2: Breadth-First Search (BFS)

**Approach:** Use a queue-based BFS for level-by-level exploration.

```python
def canUnlockAll(boxes):
    """
    Use BFS with a queue to explore all reachable boxes.
    """
    if not boxes:
        return True
    
    from collections import deque
    
    visited = set()
    queue = deque([0])  # Start with box 0
    
    while queue:
        box = queue.popleft()
        
        if box in visited:
            continue
        
        visited.add(box)
        
        # Add all keys in current box to queue
        for key in boxes[box]:
            if key not in visited and key < len(boxes):
                queue.append(key)
    
    return len(visited) == len(boxes)
```

**Time Complexity:** O(n + e)  
**Space Complexity:** O(n)

### Solution 3: Recursive DFS

**Approach:** Use recursion to explore all reachable boxes.

```python
def canUnlockAll(boxes):
    """
    Use recursive DFS to explore all reachable boxes.
    """
    visited = set()
    
    def dfs(box):
        if box in visited or box >= len(boxes) or box < 0:
            return
        
        visited.add(box)
        
        for key in boxes[box]:
            dfs(key)
    
    dfs(0)
    return len(visited) == len(boxes)
```

**Time Complexity:** O(n + e)  
**Space Complexity:** O(n + recursion depth)

---

## Step-by-Step Execution

**Example:** `boxes = [[1], [2], [3], [4], []]`

### Using DFS:

```
Initial state:
- visited = {}
- stack = [0]

Step 1: Process box 0
- visited = {0}
- Add keys: [1] -> stack = [1]

Step 2: Process box 1
- visited = {0, 1}
- Add keys: [2] -> stack = [2]

Step 3: Process box 2
- visited = {0, 1, 2}
- Add keys: [3] -> stack = [3]

Step 4: Process box 3
- visited = {0, 1, 2, 3}
- Add keys: [4] -> stack = [4]

Step 5: Process box 4
- visited = {0, 1, 2, 3, 4}
- Keys: [] -> stack is empty

Result: visited size (5) == boxes size (5) -> True
```

---

## Edge Cases

1. **Empty boxes:** `boxes = []` → Return `True` (no boxes to unlock)
2. **Single box:** `boxes = [[]]` → Return `True` (box 0 is unlocked)
3. **Unreachable box:** `boxes = [[1], [3], [], []]` → Return `False` (box 2 unreachable)
4. **Invalid key:** `boxes = [[5]]` → Return `False` (key to non-existent box)
5. **Self-referencing:** `boxes = [[0]]` → Return `True` (only box 0)
6. **Circular references:** `boxes = [[1], [0], []]` → Return `True` (0 and 1 reachable, 2 not)

---

## Compilation and Testing

```bash
chmod +x 0-lockboxes.py
python3 0-lockboxes.py
```

---

## Files in This Directory

| File | Purpose |
|---|---|
| `0-lockboxes.py` | Main solution function |
| `README.md` | This file |

---

## Requirements

- **Python:** Version 3.4.3 or higher
- **Code Style:** PEP 8 (version 1.7.x)
- **Documentation:** Properly documented with docstrings
- **Executable:** File must be executable (`chmod +x 0-lockboxes.py`)
- **Shebang:** First line must be `#!/usr/bin/python3`

---

## Key Concepts

- **Graph Theory:** Modeling the problem as a directed graph
- **Graph Traversal:** DFS and BFS algorithms
- **Reachability:** Determining which nodes are reachable from a source
- **Set Operations:** Tracking visited nodes
- **Data Structures:** Lists, sets, stacks, queues

---

## Performance Comparison

| Algorithm | Time | Space | Pros |
|---|---|---|---|
| **DFS (Stack)** | O(n+e) | O(n) | Iterative, no recursion depth limit |
| **DFS (Recursive)** | O(n+e) | O(n) | Cleaner code, easier to understand |
| **BFS (Queue)** | O(n+e) | O(n) | Level-by-level exploration |

---

## Common Mistakes to Avoid

1. **Not checking bounds:** Keys might point to non-existent boxes
2. **Not handling empty input:** Edge case of empty boxes list
3. **Forgetting to start with box 0:** Always unlock box 0 first
4. **Infinite loops:** Use a visited set to prevent cycles
5. **Wrong comparison:** Count visited nodes correctly

---

## Related Problems

- [Number of Islands (LeetCode 200)](https://leetcode.com/problems/number-of-islands/)
- [Clone Graph (LeetCode 133)](https://leetcode.com/problems/clone-graph/)
- [Surrounded Regions (LeetCode 130)](https://leetcode.com/problems/surrounded-regions/)
- [Course Schedule (LeetCode 207)](https://leetcode.com/problems/course-schedule/)

---

## Additional Resources

- [Graph Theory - Wikipedia](https://en.wikipedia.org/wiki/Graph_theory)
- [Depth-First Search (DFS)](https://en.wikipedia.org/wiki/Depth-first_search)
- [Breadth-First Search (BFS)](https://en.wikipedia.org/wiki/Breadth-first_search)
- [PEP 8 Style Guide](https://www.python.org/dev/peps/pep-0008/)
- [Python Collections Deque](https://docs.python.org/3/library/collections.html#collections.deque)

---

## Author

**Médie Noé**  
Holberton School Interview Preparation