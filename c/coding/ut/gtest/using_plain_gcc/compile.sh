#!/usr/bin/env bash

readonly SRC_FILE="${1}"

if [ ! -z ${SRC_FILE} ]; then
  # -g : for gdb
  [ -f ${SRC_FILE} ] && gcc -g -o "${SRC_FILE%.*}" ${SRC_FILE}
else
  echo "Usage ${BASH_SOURCE[0]} <file_name.c>"
fi
