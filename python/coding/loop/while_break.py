#!/usr/bin/env python3

from random import randrange

cpt = 0 
while True:
    i = randrange(10)
    j = randrange(100)
    print(f"{cpt:4} lol")
    cpt += 1
    if i == j:
        print()
        print(f"{i} == {j} sorti au bout de [{cpt}] tirage(s)")
        break
