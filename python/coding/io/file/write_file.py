#!/usr/bin/env python3

import sys


# text mode
def write_file(file_name):
    with open(file_name, "w") as f:
        # wb : write bytes
        # ab : append bytes
        msg = f"{__name__}"
        f.write(msg)


# text bianry mode
def write_file_bin(file_name):
    with open(file_name, "wb") as f:
        # wb : write bytes
        # ab : append bytes
        msg = f"{__name__}".encode() # str => bytes
        f.write(msg)


if __name__ == "__main__":
    if len(sys.argv) == 2:
        #write_file(sys.argv[1])
        write_file_bin(sys.argv[1])
