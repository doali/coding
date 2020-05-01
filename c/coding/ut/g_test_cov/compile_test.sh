#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# Compile main_test.cpp with gtest support !!
# ------------------------------------------------------------------------------
g++ -fprofile-arcs -ftest-coverage \
  -o main_test main_test.cpp \
  -L /usr/lib/ -I /usr/include/ \
  -lgtest -lpthread

#-L dir
#    To specify directories for the linker to search for the library files.

#-l library
#    This specifies a library to link with.

#-I dir
#    This specifies a directories for the compile to search for when looking for include files.

#-fprofile-arcs -ftest-coverage
#    This tells the compiler to generate additional information needed by gcov
#    (basically a flow graph of the program) and also includes additional code in
#    the object files for generating the extra profiling information needed by gcov.

# A few more words
#-fprofile-arcs 
#- `.gcda`
#    - data file
#    - needs `-fprofile-arcs` compile option to be created
#    - for each source file, we get a .gcda file
#    - profiling and coverage information
#-ftest-coverage
#- `.gcno`
#    - data file
#    - basic block construction info and line numbers
#    - thanks to `-ftest-coverage` option
