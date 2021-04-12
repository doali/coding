#!/usr/bin/env bash

readonly LIB=liboperation.a
readonly RESC_NAME=operation
readonly SRC=${RESC_NAME}.c
readonly OBJ=${RESC_NAME}.o

# Delete old lib
[ -f ${LIB} ] && rm ${LIB} && echo "${LIB} old version deleted"

# Delete old object file
[ -f ${OBJ} ] && rm ${OBJ} && echo "${OBJ} deleted"

# Compile object file
gcc -c ${SRC} && [ -f ${OBJ} ] && echo "${OBJ} created"

# Create lib
ar -q ${LIB} ${OBJ} || echo "${LIB} could not have been created"

# Check lib interface
nm ${LIB}
