#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# https://www.geeksforgeeks.org/extern-c-in-c/
# https://stackoverflow.com/questions/1041866/what-is-the-effect-of-extern-c-in-c
# ------------------------------------------------------------------------------
g++ -c ext-nothing.c # generate object file (.o) =>do_nothing(...)
g++ -o C.exe C.cpp ext-nothing.o  # linked to executable C.exe
