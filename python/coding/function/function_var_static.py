#!/usr/bin/env python2


def some_fun():
    some_fun.i += 1  # variable locale static
    print(some_fun.i)


def main():
    some_fun.i = 0
    # declaration initialisation
    some_fun()
    some_fun()
    some_fun()


if __name__ == "__main__":
    main()
