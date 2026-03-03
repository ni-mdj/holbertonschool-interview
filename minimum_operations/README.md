# Minimum Operations

## Problem Statement

In a text file, there is a single character H. Your text editor can execute only two operations:
- **Copy All** - Copy all current characters to the clipboard
- **Paste** - Paste the clipboard content into the file

Given a number `n`, write a method that calculates the **fewest number of operations** needed to result in exactly `n` H characters in the file.

**Constraint:** If `n` is impossible to achieve, return 0.

### Example
```
n = 9
H => Copy All => Paste => HH => Paste => HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH
Number of operations: 6
```

---

## Algorithm Explanation

The key insight is that **the minimum number of operations equals the sum of prime factors of n**.

### Why Prime Factorization?

To multiply the number of H's by a factor `k`, you need:
- 1 **Copy All** operation (costs 1)
- `k-1` **Paste** operations (each costs 1)
- **Total cost: k operations**

Since we want to minimize operations, we should use the smallest possible multipliers. The smallest multipliers are **prime numbers**. Therefore:

$$\text{min operations} = \sum \text{(prime factors of } n)$$

### Examples

| n | Prime Factors | Operations | Explanation |
|---|---|---|---|
| 1 | - | 0 | Already have 1 H |
| 2 | [2] | 2 | H → HH (1 copy + 1 paste) |
| 4 | [2, 2] | 4 | H → HH → HHHH |
| 6 | [2, 3] | 5 | H → HH → HHHHHH |
| 9 | [3, 3] | 6 | H → HHH → HHHHHHHHH |
| 12 | [2, 2, 3] | 7 | H → HH → HHHH → HHHHHHHHHHHH |

---

## Implementation

### Solution Approach

1. Handle edge case: if `n < 2`, return 0 (impossible or already done)
2. Find all prime factors of `n` by trial division
3. Sum all prime factors (counting multiplicities)
4. Return the sum

### Code Walkthrough

```python
def minOperations(n):
    if n < 2:
        return 0
    
    operations = 0
    factor = 2
    
    # Find all prime factors and sum them
    while n > 1:
        while n % factor == 0:
            operations += factor  # Add factor to sum
            n //= factor          # Divide n by factor
        factor += 1
    
    return operations
```

**Time Complexity:** O(√n)  
**Space Complexity:** O(1)

---

## Testing

### Run the Tests

```bash
cd /path/to/minimum_operations
python3 0-main.py
```

### Expected Output

```
Min # of operations to reach 4 char: 4
Min # of operations to reach 12 char: 7
```

### Test Cases

```python
minOperations = __import__('0-minoperations').minOperations

# Test cases
assert minOperations(1) == 0    # Already 1 H
assert minOperations(2) == 2    # [2]
assert minOperations(4) == 4    # [2, 2]
assert minOperations(6) == 5    # [2, 3]
assert minOperations(9) == 6    # [3, 3]
assert minOperations(12) == 7   # [2, 2, 3]
```

---

## Key Concepts

- **Prime Factorization:** Breaking a number into its prime factors
- **Greedy Algorithm:** Using the smallest possible factors
- **Trial Division:** Efficient method to find prime factors
- **Optimization:** Finding the minimum operations by analyzing the problem mathematically

---

## Files in This Directory

| File | Purpose |
|---|---|
| `0-minoperations.py` | Main solution function |
| `0-main.py` | Test file with examples |
| `README.md` | This file |

---

## Requirements

- **Python Version:** 3.4.3 or higher
- **Code Style:** PEP 8 (version 1.7.x)
- **Documentation:** Properly documented code with docstrings
- **Executable:** File must be executable (`chmod +x 0-minoperations.py`)
- **Shebang:** First line must be `#!/usr/bin/python3`

---

## Additional Resources

- [Prime Number - Wikipedia](https://en.wikipedia.org/wiki/Prime_number)
- [Prime Factorization - Wikipedia](https://en.wikipedia.org/wiki/Prime_factorization)
- [Trial Division - Wikipedia](https://en.wikipedia.org/wiki/Trial_division)
- [PEP 8 Style Guide](https://www.python.org/dev/peps/pep-0008/)

---

## Author

**Médie Noé**  
Holberton School Interview Preparation
