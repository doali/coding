#!/usr/bin/env bash

readonly DIR_SRC=src
readonly MAIN_SRC=Main.java
readonly MAIN_CLASS=Main.class
readonly DIR_CLASS=class

compile()
{
  if [ -d ${DIR_SRC} ]; then
    if [ -f ${DIR_SRC}/${MAIN_SRC} ]; then
      javac -d ${DIR_CLASS} -sourcepath ${DIR_SRC} ${DIR_SRC}/${MAIN_SRC}
    else
      echo "Error ${MAIN_SRC} not found"
    fi
  else
    echo "Error ${DIR_SRC} not found"
  fi
}

execute()
{
  if [ -d ${DIR_CLASS} ]; then
    cd ${DIR_CLASS} >&2 >/dev/null
    if [ -f ${MAIN_CLASS} ]; then
      java Main
    else
      echo "${MAIN_CLASS} not found"
    fi
    cd - >&2 >/dev/null
  else
    echo "class folder does not exist"
  fi
}

usage()
{
  echo "Usage $(basename ${0}) (compile|run)"
}

# ------------------------------------------------------------------------------
if [ ${#} -ne 1 ]; then
  usage
else
  case "${1}" in
    compile)
      compile
      ;;
    run)
      execute
      ;;
    *)
      usage
      ;;
  esac
fi
