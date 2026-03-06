#!/usr/bin/python3
"""Read stdin line by line and compute log metrics."""
import sys
import re


VALID_CODES = (200, 301, 400, 401, 403, 404, 405, 500)
# Pattern: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
LOG_PATTERN = r'^(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[.*\] "GET /projects/260 HTTP/1.1" (\d+) (\d+)$'


def print_stats(total_size, code_counts):
    """Print current accumulated statistics."""
    print("File size: {}".format(total_size))
    for code in VALID_CODES:
        count = code_counts.get(code, 0)
        if count:
            print("{}: {}".format(code, count))


def main():
    """Process stdin and print metrics every 10 lines."""
    total_size = 0
    valid_lines = 0
    code_counts = {code: 0 for code in VALID_CODES}

    try:
        for line in sys.stdin:
            # Try to match the log format
            match = re.match(LOG_PATTERN, line.rstrip('\n'))
            if match:
                valid_lines += 1
                status_code = int(match.group(2))
                file_size = int(match.group(3))

                total_size += file_size
                if status_code in code_counts:
                    code_counts[status_code] += 1

                if valid_lines % 10 == 0:
                    print_stats(total_size, code_counts)
    except KeyboardInterrupt:
        print_stats(total_size, code_counts)
    finally:
        # Print final stats if we have any valid lines
        if valid_lines > 0 and valid_lines % 10 != 0:
            print_stats(total_size, code_counts)


if __name__ == "__main__":
    main()
