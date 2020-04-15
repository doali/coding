#!/usr/bin/env python3

# map(func, *iterables) --> map object
# list(map) pour observer les resultats dans une liste
lp2_1 = map(lambda x: x ** x, list(range(4)))
print(list(lp2_1))

# list(...) <= obligatoire pour python3
lp2_2 = [x ** x for x in list(range(4))]
print(lp2_2)
