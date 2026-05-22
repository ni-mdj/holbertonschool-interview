# Advanced Binary Search

## Description

This project implements an advanced binary search algorithm that can handle various search scenarios beyond the basic binary search. The advanced binary search techniques include:

- **Finding the first occurrence** of a target value in a sorted array
- **Finding the last occurrence** of a target value in a sorted array
- **Finding a value in a rotated sorted array**
- **Handling duplicates** in the search array
- **Edge cases and boundary conditions**

## Problem Statement

The advanced binary search aims to efficiently search through sorted (and sometimes rotated) arrays with time complexity of **O(log n)**, which is much faster than a linear search O(n).

### Key Concepts

1. **First Occurrence**: Find the smallest index where the target value appears
2. **Last Occurrence**: Find the largest index where the target value appears
3. **Rotated Array**: Handle arrays that have been rotated at some pivot point
4. **Duplicates**: Efficiently search arrays that contain duplicate elements

## Algorithm Explanation

### Standard Binary Search
The classic binary search works on sorted arrays by repeatedly dividing the search interval in half:

```c
int binary_search(int *array, size_t size, int value)
{
    int left = 0, right = size - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (-1);
}
```

### Finding First Occurrence
```c
int search_first(int *array, size_t size, int value)
{
    int left = 0, right = size - 1;
    int result = -1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == value)
        {
            result = mid;
            right = mid - 1;  // Continue searching in left half
        }
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (result);
}
```

### Finding Last Occurrence
```c
int search_last(int *array, size_t size, int value)
{
    int left = 0, right = size - 1;
    int result = -1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == value)
        {
            result = mid;
            left = mid + 1;  // Continue searching in right half
        }
        else if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (result);
}
```

## Time & Space Complexity

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Standard Binary Search | O(log n) | O(1) |
| First Occurrence | O(log n) | O(1) |
| Last Occurrence | O(log n) | O(1) |
| Rotated Array Search | O(log n) | O(1) |

## Files

- `0-advanced_binary.c` - Main implementation of advanced binary search functions
- `README.md` - This documentation file

## Usage

To compile and test the binary search implementation:

```bash
gcc -c 0-advanced_binary.c
```

## Example

```c
#include <stdio.h>
#include "search.h"

int main(void)
{
    int array[] = {0, 1, 1, 2, 2, 2, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 8, 9, 9, 9};
    size_t size = sizeof(array) / sizeof(array[0]);
    
    printf("First occurrence of 2: %d\n", advanced_binary(array, size, 2));
    printf("Last occurrence of 8: %d\n", advanced_binary(array, size, 8));
    
    return (0);
}
```

## Author

Interview Preparation - Algorithm Series

## Resources

- [Binary Search on Wikipedia](https://en.wikipedia.org/wiki/Binary_search_algorithm)
- [Advanced Binary Search Techniques](https://www.geeksforgeeks.org/binary-search/)
- [LeetCode Binary Search Problems](https://leetcode.com/problems/binary-search/)

## Notes

- Always ensure the input array is sorted before using binary search
- Be careful with integer overflow when calculating the middle index
- Handle edge cases: empty arrays, single elements, target not found
- For rotated arrays, identify the rotation point first
