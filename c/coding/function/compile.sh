#!/usr/bin/env bash
set -x
[ $# == 1 ] && [ -f ${1} ] && gcc -Wall -ggdb -o ${1%.c} ${1} 
