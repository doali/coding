#!/usr/bin/env python3

import sys


def read_file(file_name):
    total = 0

    try:
        with open(file_name, "r") as stream:
            while True:
                read = stream.readline()
                if read == None or read == "":
                    break
                total += int(read)

    except FileNotFoundError as ex:
        print(ex)
        sys.exit(1)
    except Exception as ex:
        help()
        sys.exit(1)

    return total


def display_total(file_name):
    total = read_file(file_name)
    spelling = "s" if total > 0 else ""
    print(f"Number of line{spelling}:{total}")


def usage(prog_name):
    print(f"Usage: {prog_name} <file_name>")


def help():
    print(f"Given a file where each line contains a number")
    print(f"- compute the total")


def select(arg):
    if arg in ["-h", "--h", "help", "-help", "--help"]:
        help()
    else:
        display_total(arg)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        usage(sys.argv[0])
        sys.exit(1)
    select(sys.argv[1])
    sys.exit(0)
