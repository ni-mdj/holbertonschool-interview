# Heap Extract

## Description

This project implements the extraction (removal) of the root element from a binary heap data structure. Heap extraction is a fundamental operation in priority queues and heap-based algorithms.

The heap extract operation removes the minimum element (in a min-heap) or maximum element (in a max-heap) from the heap while maintaining the heap property.

## Problem Statement

Implement a function that:

1. **Removes the root element** from a binary heap (typically the minimum or maximum)
2. **Maintains the heap property** after removal
3. **Returns the extracted element** value
4. **Updates the heap structure** efficiently

The main challenge is to restore the heap property after removing the root by reordering elements.

## Heap Concepts

### What is a Heap?

A heap is a specialized tree-based data structure that satisfies the heap property:
- **Min-Heap**: Parent node ≤ children nodes
- **Max-Heap**: Parent node ≥ children nodes

### Heap Properties

- Complete binary tree (all levels filled except possibly the last)
- Often implemented using arrays for efficiency
- Height: O(log n)

### Array Representation

For a node at index `i`:
- **Parent**: `(i - 1) / 2`
- **Left child**: `2 * i + 1`
- **Right child**: `2 * i + 2`

## Algorithm Explanation

### Heap Extract (Min-Heap) Algorithm

```
1. Save the root element (minimum) to return later
2. Move the last element to the root position
3. Remove the last element from the heap
4. Perform "heapify down" (sift down) operation:
   a. Start from the root
   b. Compare node with its children
   c. Swap with the smaller child if child < parent
   d. Move down to the child and repeat until heap property restored
5. Return the saved minimum element
```

### Pseudocode

```
function extract_min(heap, size):
    if size == 0:
        return ERROR
    
    min_value = heap[0]  // Save root
    heap[0] = heap[size - 1]  // Move last to root
    size = size - 1  // Decrease size
    
    heapify_down(heap, 0, size)  // Restore heap property
    
    return min_value

function heapify_down(heap, index, size):
    smallest = index
    left = 2 * index + 1
    right = 2 * index + 2
    
    if left < size and heap[left] < heap[smallest]:
        smallest = left
    
    if right < size and heap[right] < heap[smallest]:
        smallest = right
    
    if smallest != index:
        swap(heap[index], heap[smallest])
        heapify_down(heap, smallest, size)
```

## C Implementation Example

```c
/**
 * extract_min - Extracts the minimum element from a min-heap
 * @heap: Pointer to the heap array
 * @size: Pointer to the current size of the heap
 *
 * Return: The minimum element value, or -1 if heap is empty
 */
int extract_min(int *heap, size_t *size)
{
    if (size == NULL || *size == 0)
        return (-1);
    
    int min_value = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    
    if (*size > 0)
        heapify_down(heap, 0, *size);
    
    return (min_value);
}

/**
 * heapify_down - Restores heap property by sifting down
 * @heap: Pointer to the heap array
 * @index: Index of element to sift down
 * @size: Current size of the heap
 */
void heapify_down(int *heap, size_t index, size_t size)
{
    size_t smallest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    
    if (smallest != index)
    {
        // Swap
        int temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;
        
        // Recursive call
        heapify_down(heap, smallest, size);
    }
}
```

## Time & Space Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Extract (Remove Root) | O(log n) | O(1) |
| Heapify Down | O(log n) | O(log n) - recursion stack |
| Extract (Iterative) | O(log n) | O(1) |

## Files

- `0-heap_extract.c` - Implementation of heap extract functionality
- `README.md` - This documentation file

## Usage

```c
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
    int heap[] = {10, 20, 30, 40, 50};
    size_t size = 5;
    
    printf("Original heap: ");
    print_heap(heap, size);
    
    int min = extract_min(heap, &size);
    printf("Extracted: %d\n", min);
    
    printf("After extraction: ");
    print_heap(heap, size);
    
    return (0);
}
```

### Example Output

```
Original heap: [10, 20, 30, 40, 50]
Extracted: 10
After extraction: [20, 40, 30, 50]
```

## Step-by-Step Example

### Initial Min-Heap

```
        10
       /  \
      20   30
     / \
    40  50
```

### Step 1: Save root and move last element

```
Root saved: 10
Move 50 to root position:
        50
       /  \
      20   30
     /
    40
```

### Step 2: Heapify Down

```
Compare 50 with children (20, 30)
Swap with smaller child (20):
        20
       /  \
      50   30
     /
    40
```

### Step 3: Continue Heapify

```
Compare 50 with child (40)
Swap with 40:
        20
       /  \
      40   30
     /
    50

Final Min-Heap: [20, 40, 30, 50]
```

## Common Applications

1. **Priority Queues**: Extract highest/lowest priority element
2. **Heap Sort**: Repeatedly extract minimum/maximum
3. **Event Simulation**: Process events in priority order
4. **Dijkstra's Algorithm**: Extract minimum distance vertex
5. **Prim's Algorithm**: Extract minimum weight edge

## Key Considerations

- **Empty Heap**: Always check if heap is empty before extracting
- **Heap Property**: Must be maintained after every extraction
- **Recursive vs Iterative**: Both approaches work; iterative is more space-efficient
- **Min vs Max Heap**: Algorithm adapts based on comparison operator
- **Array vs Pointer**: Track both the heap and its current size

## Edge Cases

- Extracting from empty heap (return error)
- Extracting from single-element heap (becomes empty)
- Extracting from heap where last element is smaller than expected
- Integer overflow considerations

## Author

Interview Preparation - Data Structures Series

## Resources

- [Binary Heap on Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)
- [Heap Sort Algorithm](https://www.geeksforgeeks.org/heap-sort/)
- [Priority Queue Implementation](https://www.geeksforgeeks.org/priority-queue-using-binary-heap/)
- [Heapify Operations](https://www.geeksforgeeks.org/heapify-a-binary-tree/)
