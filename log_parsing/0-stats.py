#!/usr/bin/python3
"""
Log parsing module that reads stdin line by line and computes metrics.
Calculates total file size and counts occurrences of status codes from a log.
Prints statistics after every 10 lines and/or keyboard interruption (CTRL + C).
"""
import sys
import signal


def print_stats(total_size, status_codes):
    """Print the statistics of the log parsing."""
    print(f"File size: {total_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")


def parse_line(line):
    """Parse a single line and return file size and status code if valid."""
    try:
        parts = line.split()
        if len(parts) < 7:
            return None, None

        # Get status code and file size from their positions
        status_code = parts[-2]
        file_size = parts[-1]

        # Validate status code and file size
        if not status_code.isdigit() or not file_size.isdigit():
            return None, None

        return int(file_size), int(status_code)
    except Exception:
        return None, None


def main():
    """Main function to process the log file."""
    total_size = 0
    line_count = 0
    status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0,
                   500: 0}

    def signal_handler(sig, frame):
        """Handle CTRL+C signal."""
        print_stats(total_size, status_codes)
        sys.exit(0)

    signal.signal(signal.SIGINT, signal_handler)

    try:
        for line in sys.stdin:
            file_size, status_code = parse_line(line)

            if file_size is not None and status_code in status_codes:
                total_size += file_size
                status_codes[status_code] += 1

            line_count += 1
            if line_count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise


if __name__ == "__main__":
    main()