import os
import re
import sys

# Directories where includes should be inlined
INLINE_INCLUDE_PATHS = [
    os.path.abspath("../include/unityraylib/raylib"),
    os.path.abspath("../include/unityraylib/raylib/external/glfw/include")
]

# Tracks files that have `#pragma once` to avoid multiple inclusion
included_files = set()

def should_inline(header_path):
    """Check if a file should be inlined based on its absolute path."""
    abs_path = os.path.abspath(header_path)
    return any(abs_path.startswith(path) for path in INLINE_INCLUDE_PATHS)

def process_file(file_path):
    abs_path = os.path.abspath(file_path)
    print(f'processing file {abs_path}', file=sys.stderr)

    # Prevent re-inclusion of files marked with #pragma once
    if abs_path in included_files:
        return

    with open(file_path, "r") as f:
        for line in f:
            # Detect #pragma once and mark file as included
            #if re.match(r'^\s*#pragma\s+once', line):
            included_files.add(abs_path)

            # Handle #include
            include_match = re.match(r'^\s*#include\s+["<](.*?)[">]', line)
            if include_match:
                include_file = include_match.group(1)

                # Check if the include file should be inlined
                for include_dir in INLINE_INCLUDE_PATHS:
                    candidate_path = os.path.join(include_dir, include_file)
                    if os.path.exists(candidate_path):
                        process_file(candidate_path)  # Recursively inline
                        break
                else:
                    # Keep the include as is if not in the allowed paths
                    print(f'keep include file as is {include_file}', file=sys.stderr)
                    print(line, end="")
            else:
                print(line, end="")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python simple_preprocessor.py <source_file>")
        sys.exit(1)

    source_file = sys.argv[1]
    process_file(source_file)
