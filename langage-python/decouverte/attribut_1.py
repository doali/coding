#!/usr/bin/env python3


class SomeClass:
    # this is a class attribute
    some_attr = 1

    def __init__(self):
        # this is an instance attribute
        self.new_attr = 2


def main():
    c1 = SomeClass()
    print(c1.new_attr)
    print(SomeClass.some_attr)


if __name__ == "__main__":
    main()
