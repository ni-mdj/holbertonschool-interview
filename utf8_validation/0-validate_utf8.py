#!/usr/bin/python3
"""
UTF-8 Validation Module
Determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data: A list of integers representing bytes of data.
              Only the 8 least significant bits of each integer are used.

    Returns:
        True if data is a valid UTF-8 encoding, False otherwise.

    UTF-8 encoding rules:
    - 1-byte character: 0xxxxxxx
    - 2-byte character: 110xxxxx 10xxxxxx
    - 3-byte character: 1110xxxx 10xxxxxx 10xxxxxx
    - 4-byte character: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
    """
    # Number of bytes remaining in the current character
    num_bytes = 0

    for num in data:
        # Get only the 8 least significant bits
        byte = num & 0xFF

        if num_bytes == 0:
            # Determine the number of bytes for this character
            if (byte >> 7) == 0:
                # 1-byte character: 0xxxxxxx
                num_bytes = 1
            elif (byte >> 5) == 0b110:
                # 2-byte character: 110xxxxx
                num_bytes = 2
            elif (byte >> 4) == 0b1110:
                # 3-byte character: 1110xxxx
                num_bytes = 3
            elif (byte >> 3) == 0b11110:
                # 4-byte character: 11110xxx
                num_bytes = 4
            else:
                # Invalid start byte
                return False

        else:
            # We're in the middle of a character, expect continuation byte
            # Continuation bytes must match pattern: 10xxxxxx
            if (byte >> 6) != 0b10:
                return False

        num_bytes -= 1

    # All characters must be complete
    return num_bytes == 0
