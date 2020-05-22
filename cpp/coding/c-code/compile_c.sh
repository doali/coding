#!/usr/bin/env bash
# ------------------------------------------------------------------------------
g++ -c ext-nothing.c # generate object file (.o) =>do_nothing(...)
g++ -o C.exe C.cpp ext-nothing.o  # linked to executable C.exe
