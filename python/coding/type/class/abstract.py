#!/usr/bin/env python3

from abc import ABCMeta, abstractmethod


class MyClass:
    # __metaclass__ = ABCMeta

    @abstractmethod
    def do_something(self):
        pass

    def __init__(self):
        print(f"{MyClass.__name__}")


class Child(MyClass):
    def do_something(self):
        print(f"learning python")


if __name__ == "__main__":
    c = Child()
    c.do_something()

    # m = MyClass()
    # m.do_something()
