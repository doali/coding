#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# These files are just for
# - what we can do with extern and static keywords
# (!) design is terrible... do not do like this !!
# ------------------------------------------------------------------------------
gcc -o main_glob_static main_glob_static.c glob_and_static.c
#glob_and_static_base.c # <= NO !! otherwise compilation error !!
