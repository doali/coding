#!/usr/bin/env python2

def some_fun():
    some_fun.i += 1
    print(some_fun.i)


def main():
    some_fun.i = 0;
    some_fun()
    some_fun()
    some_fun()


if __name__ == "__main__":
    main()
