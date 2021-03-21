#!/usr/bin/env bash

#gcc -ggdb -Wall -o exp_ioctl exp_ioctl.c
[ $# == 1 ] && [ -f ${1} ] && gcc -Wall -ggdb -o ${1%.c} ${1}
