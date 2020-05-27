#!/usr/bin/env bash
# ------------------------------------------------------------------------------
gcc -c libread.c
gcc -DINFO -c main.c # IMPORTANT d'utiliser l'option ICI !!
                     # En effet, INFO est utilisee dans main.c 
                     # (et définie dans macro.h)
ar -q libread.a libread.o
gcc -Werror -Wall -ggdb -o main.exe main.o libread.a

# ------------------------------------------------------------------------------
# Plus simplement
#gcc -DINFO -Werror -Wall -ggdb -o main.exe main.c libread.c
