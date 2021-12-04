#!/usr/bin/env python3


def f(x):
    def g(y):
        return x + y

    return g


l = list(range(10))

f_10 = f(10)

for element in l:
    print(f"{element}:f_10({element})={f_10(element)}")
