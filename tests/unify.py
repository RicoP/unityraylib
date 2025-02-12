import os
import re
import sys

# Directories where includes should be inlined
INLINE_INCLUDE_PATHS_DEFAULTS = [
    os.path.abspath("../include/unityraylib/raylib"),
    os.path.abspath("../include/unityraylib/raylib/external/glfw/include")
]

include_paths = []
miniaudio_counter = 0

# Tracks files that have `#pragma once` to avoid multiple inclusion
included_files = set()

def process_file(file_path):
    global include_paths
    global miniaudio_counter
    abs_path = os.path.abspath(file_path)
    include_dir = os.path.dirname(abs_path)

    if abs_path.endswith(".c"):
        # add the path of the current file as a potential
        # source path for the include
        if not include_dir in include_paths:
            include_paths = INLINE_INCLUDE_PATHS_DEFAULTS.copy()
            include_paths.append(include_dir)

    #print(f'processing file {abs_path}', file=sys.stderr)

    with open(abs_path, "r") as f:
        included_files.add(abs_path)
        for line in f:
            # skip #pragma once
            if re.match(r'^\s*#\s*pragma\s+once', line):
                continue

            # Handle #include
            include_match = re.match(r'^\s*#\s*include\s+["<](.*?)[">]', line)
            if include_match:
                include_file = include_match.group(1)

                # Check if the include file should be inlined
                for include_dir in include_paths:
                    candidate_path = os.path.join(include_dir, include_file)
                    candidate_path = os.path.abspath(candidate_path)
                    if os.path.exists(candidate_path):
                        if candidate_path in included_files and not include_file == "external/miniaudio.h":
                            print(f"// {line}", end="")
                            print(f'{file_path}->{include_file} ignored', file=sys.stderr)
                        else:
                            print(f'{file_path}->{include_file}', file=sys.stderr)
                            print(f"/// START {'/' * len(include_file)} START ///\n", end="")
                            print(f"///       {     include_file      }       ///\n", end="")
                            print(f"/// START {'/' * len(include_file)} START ///\n", end="")
                            process_file(candidate_path)
                            print(f"///  END  {'/' * len(include_file)}  END  ///\n", end="")
                            print(f"///       {     include_file      }       ///\n", end="")
                            print(f"///  END  {'/' * len(include_file)}  END  ///\n", end="")
                        break
                else:
                    # Keep the include as is if not in the allowed paths
                    print(line, end="")
            else:
                # keep line as is
                print(line, end="")
                # hack for miniaudio.h where the first
                # time we just want to parse the header
                if re.sub(r'\s+', '', line) == "#endif/*miniaudio_h*/":
                    miniaudio_counter += 1
                    if miniaudio_counter == 1:
                        break

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python simple_preprocessor.py <source_file>")
        sys.exit(1)

    source_file = sys.argv[1]
    process_file(source_file)
