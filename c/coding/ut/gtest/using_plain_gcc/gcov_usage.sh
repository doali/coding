#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# https://github.com/doali/coding/blob/master/c/doc/gcov.md
# (!) Do not forget to uncomment main function in main.c (if ever...)
# ------------------------------------------------------------------------------

# First compile time !!
# No gtest (googletest) here !!
gcc -o main -fprofile-arcs -ftest-coverage main.c

# Then => run !!
./main 1 2 3

# Next, generation (branch option)
gcov -b main.c

# Let us check the outcome
cat main.c.gcov
