#!/usr/bin/env bash
# ------------------------------------------------------------------------------
gcc -c *.c
ar -q libread.a libread.o
gcc -Werror -Wall -ggdb -o main.exe main.o libread.a
