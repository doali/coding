#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# https://github.com/doali/coding/blob/master/c/doc/gtest.md
# ------------------------------------------------------------------------------

# compile time (check that main function in main.c is well uncommented)
./compile.sh main.c

# Comment main function in man.c (so that beeing able to compile main_test.cpp)
./compile_test.sh 
