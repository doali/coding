#!/usr/bin/env python3

# https://www.bogotobogo.com/python/python_closure.php


def closure(a):
    return lambda x: a ** x


f_10 = closure(10)

for i in range(10):
    res = f_10(i)
    print(res)
