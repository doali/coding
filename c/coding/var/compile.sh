#!/usr/bin/env bash

usage() {
  echo "Usage: $0 <source.c>"
}

# -ggdb : set on symbols for gdb
[ ${#} == 1 ] && [ ! -z ${1} ] && [ -f ${1} ] && gcc -ggdb -o "${1%.*}" ${1} || usage
