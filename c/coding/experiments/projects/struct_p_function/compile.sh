#!/usr/bin/bash

readonly TARGET=main

info() {
  local msg=$1

  echo
  echo "$1 -----------------------------------------------------------------------------"
  echo
}

info "compile"
gcc -o ${TARGET} *.c

[ -f ${TARGET} ] || exit 1

info "valgrind"
valgrind ./${TARGET}

info "run"
[ -f ${TARGET} ] && ./${TARGET}

info "clean"
[ -f ${TARGET} ] && rm ${TARGET}
