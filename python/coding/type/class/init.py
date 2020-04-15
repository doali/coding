#!/usr/bin/env python3

class Pattern(object):
    def __new__(cls):
        print("__new__")
        return super(Pattern, cls).__new__(cls)

    def __init__(self):
        #super().__init__()
        print("__init__")

    def __del__(self):
        print(f"__del__ called")

if __name__ == '__main__':
    inst = Pattern()
    print(f"Instance: {inst}")
