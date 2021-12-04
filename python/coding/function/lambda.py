#!/usr/bin/env python3

# Currification / Curryfication
# https://medium.com/elp-2018/la-curryfication-au-coeur-de-la-programmation-fonctionnelle-5fd50ce0e858

# Lambda function (defined then called)
l = lambda x, y: x + y
res = l(4, 5)
print(f"{res}")

# Lambda function (defined and immediately called)
res = (lambda x, y: x + y)(4, 5)
print(f"{res}")

# For the following examples ------
l = list(range(4))
print(f"l={l}")

# Inner function ---
def f(a):
    def g(b):
        return a + b
    return g

f_10 = f(10) # got function
res = list(map(f_10, l))
print(f"{res}")

# Curryfication ---
t = (lambda a: (lambda b: a + b))
res = list(map(t(10), l))
print(f"{res}")
