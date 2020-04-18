#!/usr/bin/env python3

import sys

def decorator(func):
    def wrapper(*args, **kwargs):
        print(f"{decorator.__name__}")
        return func(*args, **kwargs)
    return wrapper

@decorator
def decorated(name):
    msg = f"I've been called {name}"
    return msg


if __name__ == '__main__':
    ret = decorated(sys.argv[1] if (len(sys.argv) == 2) else "")
    print(ret)
