#!/usr/bin/env python3

import sys

# Python3 => utilisation de list
l = list(range(10))

for element in l:
    sys.stdout.write(f"{element}")
    sys.stdout.flush()

print("")

for i, item in enumerate(l):
    print(f"{i} {item} {l[i:]}")
