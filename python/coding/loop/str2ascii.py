#!/usr/bin/env python3

import sys


def str2ascii(message):
    """convert message to ascii"""
    for c in message:
        print(f"|{ord(c):3}|{c:1}|", sep="|")


def main(message):
    # Classic way
    str2ascii(message)

    print()

    # Python style
    print(*[ord(c) for c in list(message)])


# ------------------------------------------------------------------------------
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <string>")
    else:
        main(sys.argv[1])
