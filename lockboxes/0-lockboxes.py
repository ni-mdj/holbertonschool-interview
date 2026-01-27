#!/usr/bin/python3
"""Lockboxes module."""


def canUnlockAll(boxes):
    """Return True if all boxes can be opened, else False."""
    if not isinstance(boxes, list) or not boxes:
        return False

    n = len(boxes)
    opened = [False] * n
    opened[0] = True
    keys = list(boxes[0])

    while keys:
        key = keys.pop()
        if isinstance(key, int) and 0 <= key < n and not opened[key]:
            opened[key] = True
            keys.extend(boxes[key])

    return all(opened)
