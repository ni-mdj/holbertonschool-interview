#!/usr/bin/python3
"""Main file for testing lockboxes"""

canUnlockAll = __import__('0-lockboxes').canUnlockAll

# Test case 1: All boxes can be opened
boxes = [[1], [2], [3], [4], []]
print("Test 1 - boxes = {}".format(boxes))
print("Result: {}".format(canUnlockAll(boxes)))
print()

# Test case 2: Box 1 cannot be reached
boxes = [[1, 2], [3], [4], []]
print("Test 2 - boxes = {}".format(boxes))
print("Result: {}".format(canUnlockAll(boxes)))
print()

# Test case 3: Empty boxes
boxes = []
print("Test 3 - boxes = {}".format(boxes))
print("Result: {}".format(canUnlockAll(boxes)))
print()

# Test case 4: Single box with self-key
boxes = [[0]]
print("Test 4 - boxes = {}".format(boxes))
print("Result: {}".format(canUnlockAll(boxes)))
print()

# Test case 5: Circular references
boxes = [[1], [0], []]
print("Test 5 - boxes = {}".format(boxes))
print("Result: {}".format(canUnlockAll(boxes)))
print()

# Test case 6: All keys needed
boxes = [[1, 2, 3, 4], [], [], [], []]
print("Test 6 - boxes = {}".format(boxes))
print("Result: {}".format(canUnlockAll(boxes)))
