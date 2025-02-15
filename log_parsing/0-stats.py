#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys


def print_stats(total_size, status_codes):
    """Print accumulated statistics"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


def main():
    """Main function to process log lines"""
    total_size = 0
    line_count = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0,
                   403: 0, 404: 0, 405: 0, 500: 0}

    try:
        for line in sys.stdin:
            try:
                parts = line.split()
                if len(parts) > 2:
                    status_code = int(parts[-2])
                    file_size = int(parts[-1])
                    
                    # Update metrics
                    total_size += file_size
                    if status_code in status_codes:
                        status_codes[status_code] += 1
                    
                    line_count += 1
                    
                    # Print stats every 10 lines
                    if line_count % 10 == 0:
                        print_stats(total_size, status_codes)
                        
            except (ValueError, IndexError):
                continue
                
    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_codes)


if __name__ == "__main__":
    main()