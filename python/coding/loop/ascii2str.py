#!/usr/bin/env python3

import sys


def ascii2str(msgASCII):
    """convert message to ascii"""
    for c in msgASCII:
        print(f"|{c:3}|{chr(int(c)):1}|", sep="|")


def main(msgToDecode):
    # Classic way
    ascii2str(msgToDecode)

    print()

    # Python style
    print(*[chr(int(c)) for c in list(msgToDecode)])


# ------------------------------------------------------------------------------
if __name__ == "__main__":
    if len(sys.argv) == 1:
        print(f"Usage: {sys.argv[0]} <numbers>")
    else:
        main(sys.argv[1:])
