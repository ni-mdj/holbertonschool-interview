#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics.

Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C), prints statistics.
"""

import sys
import re
import signal


def print_stats(status_codes, total_size):
    """
    Print statistics about file size and status codes.

    Args:
        status_codes: Dictionary with status codes as keys and counts as values
        total_size: Total file size accumulated
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        print("{}: {}".format(code, status_codes[code]))


def signal_handler(sig, frame):
    """
    Handle KeyboardInterrupt (CTRL + C) signal.

    Args:
        sig: The signal number
        frame: The current stack frame
    """
    print_stats(status_codes, total_size)
    sys.exit(0)


def is_valid_line(line):
    """
    Check if a line matches the expected format.

    Args:
        line: The line to validate

    Returns:
        Tuple (is_valid, ip, status_code, file_size) or (False, None, None, None)
    """
    pattern = (
        r'^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[.*?\] "GET /projects/260 HTTP/1\.1" '
        r'(\d{3}) (\d+)$'
    )
    match = re.match(pattern, line)
    if match:
        try:
            status_code = int(match.group(2))
            file_size = int(match.group(3))
            return True, match.group(1), status_code, file_size
        except ValueError:
            return False, None, None, None
    return False, None, None, None


# Initialize variables
status_codes = {}
total_size = 0
line_count = 0
valid_status_codes = [200, 301, 400, 401, 403, 404, 405, 500]

# Set up signal handler for CTRL + C
signal.signal(signal.SIGINT, signal_handler)

# Main loop to read lines from stdin
try:
    for line in sys.stdin:
        line = line.strip()
        is_valid, ip, status_code, file_size = is_valid_line(line)

        if is_valid:
            # Update total size
            total_size += file_size

            # Update status code count if it's a valid status code
            if status_code in valid_status_codes:
                if status_code not in status_codes:
                    status_codes[status_code] = 0
                status_codes[status_code] += 1

            # Increment line counter
            line_count += 1

            # Print stats after every 10 valid lines
            if line_count % 10 == 0:
                print_stats(status_codes, total_size)

except KeyboardInterrupt:
    # Handle CTRL + C
    print_stats(status_codes, total_size)
    sys.exit(0)
