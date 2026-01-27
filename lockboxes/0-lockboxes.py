#!/usr/bin/python3
def canUnlockAll(boxes):
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