# UTF-8 Validation

## Description
This project contains a solution to determine if a given data set represents a valid UTF-8 encoding.

## Task
Write a method that validates UTF-8 encoding according to the UTF-8 standard.

### Prototype
```python
def validUTF8(data)
```

### Requirements
- Return `True` if data is a valid UTF-8 encoding, else return `False`
- A character in UTF-8 can be 1 to 4 bytes long
- The data set can contain multiple characters
- The data will be represented by a list of integers
- Each integer represents 1 byte of data (only the 8 least significant bits are used)

## UTF-8 Encoding Rules
UTF-8 uses a variable-length encoding scheme:

1. **1-byte character**: `0xxxxxxx` (0x00-0x7F)
2. **2-byte character**: `110xxxxx 10xxxxxx` (0xC0-0xDF followed by 0x80-0xBF)
3. **3-byte character**: `1110xxxx 10xxxxxx 10xxxxxx` (0xE0-0xEF followed by two 0x80-0xBF bytes)
4. **4-byte character**: `11110xxx 10xxxxxx 10xxxxxx 10xxxxxx` (0xF0-0xF7 followed by three 0x80-0xBF bytes)

## Files
- `0-validate_utf8.py` - Main solution file containing the `validUTF8` function
- `0-main.py` - Test file with example usage

## Usage
```bash
./0-main.py
```

## Examples
```python
validUTF8([65])  # True (single ASCII character 'A')
validUTF8([80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33])  # True ("Python is cool!")
validUTF8([229, 65, 127, 256])  # False (invalid UTF-8 sequence)
```

## Algorithm
The solution uses a state machine approach:
1. Track the number of bytes expected for the current character
2. For each byte in the input:
   - If no bytes are expected, this byte should be a start byte determining the character length
   - If bytes are expected, this byte should be a continuation byte (10xxxxxx pattern)
3. Return `True` only if all characters are complete at the end

## Author
Carrie Ybay, Software Engineer at Holberton School
