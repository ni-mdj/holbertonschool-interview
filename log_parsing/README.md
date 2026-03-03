# Log Parsing

## Problem Statement

Write a Python script that reads stdin line by line and computes metrics about log data.

### Input Format

Each valid log line must match this format:
```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

**Rules:**
- Lines that don't match the format must be skipped
- Status codes should be integers in the set: {200, 301, 400, 401, 403, 404, 405, 500}
- Invalid or non-matching lines are ignored

### Output

After every 10 valid lines **and/or** when receiving a keyboard interruption (CTRL + C), print:

1. **Total file size:** Sum of all `<file size>` values seen so far
2. **Status code counts:** Number of times each status code appears (in ascending order)

**Format:**
```
File size: <total_size>
<status_code>: <count>
<status_code>: <count>
...
```

---

## Algorithm Explanation

### Approach

1. **Read stdin line by line** - Process streaming data
2. **Validate each line** - Use regex to match the expected format
3. **Track metrics** - Maintain cumulative total size and status code counts
4. **Print on triggers** - Output statistics every 10 valid lines or on CTRL+C
5. **Handle signals** - Use signal handler for graceful termination

### Key Components

#### 1. Input Validation
```python
pattern = r'^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[.*?\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
```
- Validates IP address format
- Checks date/time placeholder
- Ensures correct HTTP request format
- Extracts status code and file size

#### 2. Line Processing
- Count only valid lines
- Ignore lines that don't match the format
- Update cumulative statistics

#### 3. Signal Handling
- Register SIGINT handler for CTRL+C
- Print final statistics before exiting
- Ensure data integrity on interruption

---

## Time and Space Complexity

| Metric | Complexity | Notes |
|--------|-----------|-------|
| **Time per line** | O(n) | regex matching is O(n) where n is line length |
| **Space** | O(1) | only storing counts and total size |
| **Total Time** | O(m×n) | m lines, n avg line length |

---

## Implementation Details

### Core Data Structures

```python
status_codes = {}        # Dictionary to count each status code
total_size = 0          # Cumulative total file size
line_count = 0          # Counter for valid lines
valid_status_codes = [200, 301, 400, 401, 403, 404, 405, 500]
```

### Functions

#### `is_valid_line(line)`
Validates a log line and extracts required fields.

**Parameters:**
- `line` (str): The log line to validate

**Returns:**
- Tuple: `(is_valid, ip, status_code, file_size)` or `(False, None, None, None)`

**Logic:**
1. Apply regex pattern to line
2. Extract matched groups
3. Convert to integers and validate
4. Return validation result with extracted values

#### `print_stats(status_codes, total_size)`
Prints the current statistics.

**Parameters:**
- `status_codes` (dict): Dictionary of status codes and their counts
- `total_size` (int): Total file size accumulated

**Output Format:**
```
File size: <total_size>
200: <count>
301: <count>
...
```

#### `signal_handler(sig, frame)`
Handles CTRL+C interruption.

**Behavior:**
1. Catches SIGINT signal
2. Prints final statistics
3. Exits gracefully

---

## Example Execution

### Sample Input (10 lines)
```
192.168.1.1 - [2026-03-04 12:34:56] "GET /projects/260 HTTP/1.1" 200 512
10.0.0.1 - [2026-03-04 12:34:57] "GET /projects/260 HTTP/1.1" 404 256
172.16.0.1 - [2026-03-04 12:34:58] "GET /projects/260 HTTP/1.1" 200 1024
...
```

### Output (after 10 lines)
```
File size: 5213
200: 2
301: 1
400: 1
401: 1
403: 1
404: 2
405: 1
500: 1
```

### With CTRL+C
```
^CFile size: 12567
200: 4
301: 2
400: 2
401: 2
403: 3
404: 4
405: 2
500: 1
```

---

## Edge Cases

### 1. Invalid Lines
Lines that don't match the format are **silently skipped**:
```
invalid log line            # Skipped
192.168.1.1 - invalid       # Skipped
```

### 2. Empty Status Codes
If a status code never appears, it's **not printed**:
```
File size: 1024
200: 5
404: 3
# 301, 400, 401, 403, 405, 500 are not printed
```

### 3. Non-integer Values
Lines with non-integer status codes or file sizes are **skipped**:
```
192.168.1.1 - [...] "GET /projects/260 HTTP/1.1" abc 512   # Skipped
192.168.1.1 - [...] "GET /projects/260 HTTP/1.1" 200 xyz   # Skipped
```

### 4. Unknown Status Codes
Status codes not in the valid set are **ignored**:
```
192.168.1.1 - [...] "GET /projects/260 HTTP/1.1" 418 256   # Counted but not printed
```

### 5. Empty Input
If no valid lines are received:
```
File size: 0
# No status codes printed
```

---

## Testing

### Using the Generator Script

```bash
./0-generator.py | ./0-stats.py
```

This will:
1. Generate 10,000 random log lines
2. Pipe them to the stats script
3. Print statistics every 10 lines
4. Exit when the generator finishes

### Manual Testing

```bash
# Test with a few lines
echo '192.168.1.1 - [2026-03-04 12:34:56] "GET /projects/260 HTTP/1.1" 200 512' | ./0-stats.py
echo '10.0.0.1 - [2026-03-04 12:34:57] "GET /projects/260 HTTP/1.1" 404 256' | ./0-stats.py
```

### Test with Invalid Lines

```bash
cat << 'EOF' | ./0-stats.py
192.168.1.1 - [2026-03-04 12:34:56] "GET /projects/260 HTTP/1.1" 200 512
invalid line
10.0.0.1 - [2026-03-04 12:34:57] "GET /projects/260 HTTP/1.1" 404 256
another invalid
192.168.1.2 - [2026-03-04 12:34:58] "GET /projects/260 HTTP/1.1" 200 1024
192.168.1.3 - [2026-03-04 12:34:59] "GET /projects/260 HTTP/1.1" 301 2048
192.168.1.4 - [2026-03-04 12:35:00] "GET /projects/260 HTTP/1.1" 401 512
192.168.1.5 - [2026-03-04 12:35:01] "GET /projects/260 HTTP/1.1" 403 256
192.168.1.6 - [2026-03-04 12:35:02] "GET /projects/260 HTTP/1.1" 405 512
192.168.1.7 - [2026-03-04 12:35:03] "GET /projects/260 HTTP/1.1" 500 1024
192.168.1.8 - [2026-03-04 12:35:04] "GET /projects/260 HTTP/1.1" 200 256
192.168.1.9 - [2026-03-04 12:35:05] "GET /projects/260 HTTP/1.1" 400 128
192.168.1.10 - [2026-03-04 12:35:06] "GET /projects/260 HTTP/1.1" 200 512
EOF
```

---

## Key Concepts

- **Regular Expressions:** Pattern matching for log line validation
- **Signal Handling:** SIGINT handling for graceful shutdown
- **Streaming Data:** Processing data line by line from stdin
- **Data Aggregation:** Accumulating statistics over time
- **State Management:** Maintaining counts and totals across iterations

---

## Files in This Directory

| File | Purpose |
|---|---|
| `0-stats.py` | Main log parsing solution |
| `0-generator.py` | Test data generator |
| `README.md` | This file |

---

## Requirements

- **Python:** Version 3.4.3 or higher
- **Code Style:** PEP 8 (version 1.7.x)
- **Executable:** File must be executable (`chmod +x 0-stats.py`)
- **Shebang:** First line must be `#!/usr/bin/python3`
- **No side effects on import:** Code uses `if __name__ == '__main__'` pattern or main logic at module level

---

## Pattern Breakdown

### Regex Pattern Explanation

```regex
^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[.*?\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$
```

| Part | Meaning |
|------|---------|
| `^` | Start of line |
| `(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})` | IP address (4 groups of 1-3 digits) |
| ` - ` | Literal " - " separator |
| `\[.*?\]` | Date in brackets (any characters, non-greedy) |
| ` "GET /projects/260 HTTP/1\.1" ` | Exact request format |
| `(\d{3})` | Status code (3 digits) |
| ` ` | Space separator |
| `(\d+)` | File size (one or more digits) |
| `$` | End of line |

---

## Common Issues & Solutions

### Issue: Script doesn't run
**Solution:** Ensure it's executable with `chmod +x 0-stats.py`

### Issue: CTRL+C doesn't print stats
**Solution:** Make sure signal handler is registered before the main loop

### Issue: Output shows blank lines
**Solution:** Check that invalid lines are being skipped correctly

### Issue: Status codes missing from output
**Solution:** Verify that the status code is in the valid set and appears in input

---

## Additional Resources

- [Python Regular Expressions](https://docs.python.org/3/library/re.html)
- [Signal Handling in Python](https://docs.python.org/3/library/signal.html)
- [Reading from stdin](https://docs.python.org/3/library/sys.html#sys.stdin)
- [PEP 8 Style Guide](https://www.python.org/dev/peps/pep-0008/)

---

## Author

**Médie Noé**  
Holberton School Interview Preparation
