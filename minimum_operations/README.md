# Minimum Operations

## Description
This project solves the "Minimum Operations" problem, which calculates the fewest number of operations needed to result in exactly `n` H characters in a file.

Starting with a single character H, you can only perform two operations:
1. **Copy All** - Copy all current characters
2. **Paste** - Paste the copied characters

## Algorithm
The solution is based on prime factorization. The minimum number of operations equals the sum of all prime factors of `n`.

### Why?
- To multiply the number of H's by a factor `k`, you need:
  - 1 Copy All operation
  - `k-1` Paste operations
  - Total: `k` operations

- Since we want the minimum, we should use the smallest possible factors
- The smallest factors are prime numbers
- Therefore, the minimum operations = sum of prime factors

### Examples
- `n = 4`: Prime factors are [2, 2], operations = 2 + 2 = 4
  - H → HH (×2: 1 copy + 1 paste) → HHHH (×2: 1 copy + 1 paste)
  
- `n = 9`: Prime factors are [3, 3], operations = 3 + 3 = 6
  - H → HHH (×3: 1 copy + 2 pastes) → HHHHHHHHH (×3: 1 copy + 2 pastes)
  
- `n = 12`: Prime factors are [2, 2, 3], operations = 2 + 2 + 3 = 7

## Usage
```bash
./0-minoperations.py
```

Or import the function:
```python
minOperations = __import__('0-minoperations').minOperations
print(minOperations(4))   # Output: 4
print(minOperations(12))  # Output: 7
```
