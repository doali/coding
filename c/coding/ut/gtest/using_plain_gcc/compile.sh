#!/usr/bin/env bash

readonly SRC_FILE="${1}"

if [ ! -z ${SRC_FILE} ]; then
  [ -f ${SRC_FILE} ] && gcc -o "${SRC_FILE%.*}" ${SRC_FILE}
else
  echo "Usage ${BASH_SOURCE[0]} <file_name.c>"
fi
