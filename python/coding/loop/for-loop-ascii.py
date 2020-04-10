#!/usr/bin/env python3

import sys


def display_ascii_table(start, end):
    for i in list(range(start, end + 1)):
        print(f"{i:3} <- {chr(i)}")


def display_ascii_char(element):
    print(chr(element))


def display_ascii_code(element):
    for i in element:
        print(f"{ord(i):3} <- {i}")


def is_one_character(element):
    return len(element) == 1 and element.isalpha()


def usage():
    print(f"Usage: {sys.argv[0]} (<char>|<digit_start> <digit_end>)")


def main():
    if len(sys.argv) == 3:
        arg_start = sys.argv[1]
        arg_end = sys.argv[2]

        if arg_start.isdigit() and arg_end.isdigit():
            if arg_start > arg_end:
                usage()
            else:
                display_ascii_table(int(arg_start), int(arg_end))
        else:
            usage()
    elif len(sys.argv) == 2:
        arg_1 = sys.argv[1]
        if arg_1.isalpha():
            display_ascii_code(arg_1)
        elif arg_1.isdigit():
            display_ascii_char(int(arg_1))
        else:
            usage()
    else:
        usage()


if __name__ == "__main__":
    main()
