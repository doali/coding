#!/usr/bin/env python3

import sys

# Python3 => utilisation de list
l = list(range(10))

for element in l:
    sys.stdout.write(element.__str__())
    sys.stdout.flush()
