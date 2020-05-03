#!/usr/bin/env bash
[ ${#} == 1 ] && gcc -ggdb -o ${1%.*} ${1} || echo "Usage: ${0} <source.c>"
