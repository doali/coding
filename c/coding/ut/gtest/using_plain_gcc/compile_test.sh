#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# Compile main.c with gtest support !!
# ------------------------------------------------------------------------------
g++ -o main_test main_test.cpp -L /usr/lib/ -I /usr/include/ -lgtest -lpthread

#-L dir
#    To specify directories for the linker to search for the library files.
#-l library
#    This specifies a library to link with.
#-I dir
#    This specifies a directories for the compile to search for when looking for include files.
