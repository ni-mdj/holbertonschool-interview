# Rain

Calculate the amount of rainwater retained after it rains on a series of walls.

## Problem

Given a list of non-negative integers representing the heights of walls with unit width 1, calculate how many square units of water will be retained after it rains.

## Solution

The algorithm uses a dynamic programming approach:

1. **Calculate left_max**: For each position, store the maximum wall height to its left
2. **Calculate right_max**: For each position, store the maximum wall height to its right
3. **Calculate water trapped**: For each position, the water level is the minimum of left_max and right_max. The water trapped at that position is the water level minus the wall height.

## Time Complexity

- O(n) where n is the length of the walls list
- Three passes through the list: one for left_max, one for right_max, and one for calculating water

## Space Complexity

- O(n) for storing left_max and right_max arrays

## Example

```python
#!/usr/bin/python3
from 0-rain import rain

walls = [0, 1, 0, 2, 0, 3, 0, 4]
print(rain(walls))  # Output: 6

walls = [2, 0, 0, 4, 0, 0, 1, 0]
print(rain(walls))  # Output: 6
```

### Visual Representation

For `[0, 1, 0, 2, 0, 3, 0, 4]`:
```
      |
    | |
  | | |
| | | | | | | |
0 1 0 2 0 3 0 4
```
Water trapped: 6 units

For `[2, 0, 0, 4, 0, 0, 1, 0]`:
```
| |   |
| | | |
| | | | | | | |
2 0 0 4 0 0 1 0
```
Water trapped: 6 units

## Requirements

- Allowed editors: vi, vim, emacs
- All files will be interpreted on Ubuntu 14.04 LTS using python3 (version 3.4.3)
- All files should end with a new line
- The first line of all files should be exactly `#!/usr/bin/python3`
- Code should use PEP 8 style (version 1.7.x)
- No module imports allowed
- All modules and functions must be documented
- All files must be executable

## Files

- `0-rain.py` - Main implementation of the rain water calculation
