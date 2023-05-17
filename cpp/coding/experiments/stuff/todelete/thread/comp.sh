#!/bin/bash - 

FILE_MAIN=$1
LIB=lpthread # std::thread !!

g++ -ggdb -o ${FILE_MAIN%.cpp} ${FILE_MAIN} -${LIB}
