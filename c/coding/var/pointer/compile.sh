#!/usr/bin/env bash
if [ ${#} == 1 ]; then
  if [ -f ${1} ]; then
    gcc -ggdb -o ${1%.*} ${1}
  else
    echo "${1} not found"
  fi
else 
  echo "Usage: ${0} <source.c>"
fi
