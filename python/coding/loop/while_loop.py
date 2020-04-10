#!/usr/bin/env python3

import time

timer = 0.8
nb_cycle = 5

print("debut timer de + " + str(timer) + " seconde")

cpt = 0
while cpt < nb_cycle:
    cpt += 1
    print(cpt)
    time.sleep(timer)

print("fin timer")
