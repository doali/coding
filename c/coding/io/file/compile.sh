#!/usr/bin/env bash
# ------------------------------------------------------------------------------
gcc -c a.c                 # 1
gcc -o file.exe file.c a.o # 2
#gcc -o file.exe *.c       # 1 && 2 at once
