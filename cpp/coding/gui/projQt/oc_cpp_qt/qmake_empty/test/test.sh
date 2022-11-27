#!/usr/bin/bash

# ------------------------------------------------------------------------------
# How to use qmake and make
# https://doc.qt.io/qt-6/qmake-tutorial.html 
# ------------------------------------------------------------------------------
# dim. 27 nov. 2022 14:06:04 CET
# ------------------------------------------------------------------------------

# scenario custom and silly
#qmake -o titi_makefile test.pro
#make -f titi_makefile # need to specify makefile name since it is not Makefile
#make -f titi_makefile clean # to removed all created file using make

# scenario
qmake
make
make clean
