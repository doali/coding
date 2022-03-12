#!/bin/bash

FILE_MAIN=$1

[ $# == 1 ] && g++ -ggdb -o ${FILE_MAIN%.cpp} ${FILE_MAIN} || echo $0 "<file_name.cpp>"
