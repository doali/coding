#!/usr/bin/env python3

def display(l):
    fmt = f"{hex(id(l))}:{l}"
    print(fmt)

l = list(range(8))
display(l)

# Comprehension (de liste)
lc_pair = [value for value in l if (value % 2 == 0)]
display(l)
display(lc_pair)

# Generator (à executer une fois, valeur à la volée)
lg_pair = (value for value in l if (value % 2 == 0))
display(l)
display(list(lg_pair))
