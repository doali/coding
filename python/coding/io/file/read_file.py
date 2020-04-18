#!/usr/bin/env python3

import sys


def read_file(file_path):
    with open(file_path, "r") as f:
        for line in f:
            print(line, end="")


if __name__ == "__main__":
    if len(sys.argv) == 2:
        read_file(sys.argv[1])
    else:
        print("file name expected on command line")
