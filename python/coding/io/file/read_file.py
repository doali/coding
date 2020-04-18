#!/usr/bin/env python3

import sys


# text mode
def read_file(file_path):
    # r : read
    # w : write
    # a : appends
    # r+ : both reading and writing
    with open(file_path, "r") as text_mode_file:
        for line in text_mode_file:
            print(line, end="")

# binary mode
def read_file_bin(file_path):
    # rb
    with open(file_path, "rb") as binary_mode_file:
        data = binary_mode_file.read()
        print(data)

if __name__ == "__main__":
    if len(sys.argv) == 3:
        if sys.argv[1] == "-t":
            read_file(sys.argv[2])
        elif sys.argv[1] == "-b":
            read_file_bin(sys.argv[2])
        else:
            print("file name expected on command line")
    else:
        print("file name expected on command line")
