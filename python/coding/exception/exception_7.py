#!/usr/bin/env python3

import sys


def read(file_name):
    try:
        stream = open(file_name, "r")
    except Exception as ex:
        print(ex)
    else:
        while True:
            read = stream.read()
            if read:
                print(f"{read}", end="")
            else:
                break


if __name__ == "__main__":
    if len(sys.argv) == 2:
        read(sys.argv[1])
