#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys
import re


def print_stats(total_size, status_codes):
    """Print accumulated statistics"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def extract_info(line):
    """Extract status code and file size from log line"""
    try:
        line = line.strip()
        pattern = r'^.*"GET /projects/260 HTTP/1.1" (\d+) (\d+)$'
        match = re.match(pattern, line)
        if match:
            return int(match.group(1)), int(match.group(2))
    except Exception:
        pass
    return None, None


def main():
    """Main function to process log lines"""
    total_size = 0
    line_count = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0,
                   403: 0, 404: 0, 405: 0, 500: 0}

    try:
        for line in sys.stdin:
            status_code, file_size = extract_info(line)
            
            if file_size is not None:
                total_size += file_size
                if status_code in status_codes:
                    status_codes[status_code] += 1
                
                line_count += 1
                if line_count % 10 == 0:
                    print_stats(total_size, status_codes)
                    
    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_codes)


if __name__ == "__main__":
    main()