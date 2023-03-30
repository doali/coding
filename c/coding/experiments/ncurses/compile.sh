#!/usr/bin/bash

gcc -Wall ${1} -o ${1%.c} -lncurses -lm
