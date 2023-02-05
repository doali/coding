#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# Compile dbus-ping-pong.c
# BECAREFULL !! order => my sources and then pkg-config
# https://stackoverflow.com/questions/37133522/gcc-undefined-reference-to-dbus
# ------------------------------------------------------------------------------

info_dbus() {
	pkg-config --cflags dbus-1
	pkg-config --libs dbus-1
}

#info_dbus

gcc -Wall dbus-ping-pong.c -o ping-pong $(pkg-config --cflags --libs dbus-1)
