#!/usr/bin/env python3

def my_decorator(func):
    def wrapper():
        print(f"{my_decorator.__name__} <- in")
        func()
        print(f"{my_decorator.__name__} <- out")

    return wrapper

@my_decorator
def func_decorated():
    print(f"I've been called")

if __name__ == '__main__':
    func_decorated()
