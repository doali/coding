#!/bin/bash - 

FILE_MAIN=$1

g++ -ggdb -o ${FILE_MAIN%.cpp} ${FILE_MAIN}
