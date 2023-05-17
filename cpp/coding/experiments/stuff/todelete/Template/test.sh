#!/usr/bin/env bash

readonly BUILD=build
readonly EXE=template

[ -d ${BUILD} ] && rm -rf ${BUILD}
mkdir ${BUILD} && cd ${BUILD} && cmake .. && make && ./${EXE}
