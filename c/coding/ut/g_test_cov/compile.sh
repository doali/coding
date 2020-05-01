#!/usr/bin/env bash
# ------------------------------------------------------------------------------
# Simple compile !!
# No gtest nor gcov !!
# ------------------------------------------------------------------------------
# BUT adding debugger option for GDB => -g or else -ggdb
# ------------------------------------------------------------------------------

readonly SRC_FILE="${1}"

if [ ! -z ${SRC_FILE} ]; then
  # -g : for gdb
  [ -f ${SRC_FILE} ] && gcc -g -o "${SRC_FILE%.*}" ${SRC_FILE} || echo "${SRC_FILE} does not exist"
else
  echo "Usage ${BASH_SOURCE[0]} <file_name.c>"
fi
