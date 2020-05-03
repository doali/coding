#!/usr/bin/env bash
set -x
gcc -ggdb -o ${1%.*} ${1}
