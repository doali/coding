#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# https://github.com/doali/coding/blob/master/c/doc/gtest.md
# https://github.com/doali/coding/blob/master/c/doc/gcov.md
# ------------------------------------------------------------------------------

# Compile time (check that main function in main.c is well uncommented)
#./compile.sh main.c

# Comment main function in main.c (so that beeing able to compile main_test.cpp)
./compile_test.sh 

# Run the executable file main_test
# it will generate files required for coverage report generation
./main_test

# Generate coverage report
# .gcov files
gcov -b main_test.cpp

# Generate info files (made with .gcno and .gcda files)
lcov --capture --directory . --output-file main_test_coverage.info

# Generate HTML file
genhtml main_test_coverage.info --output-directory main_test_report

# Browser
firefox --new-tab main_test_report/index.html
