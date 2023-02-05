#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# Compile dbus-example-matthew.c
# BECAREFULL !! order => my sources and then pkg-config
# https://stackoverflow.com/questions/37133522/gcc-undefined-reference-to-dbus
# ------------------------------------------------------------------------------
#pkg-config --cflags dbus-1
#pkg-config --libs dbus-1

in_progress_details() {
	gcc -Wall dbus-example-matthew.c -o mdbus -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -ldbus-1
}

# No need to use this one
# Kept just in case of future problems...
in_progress_pkg_full() {
	gcc -Wall dbus-example-matthew.c `pkg-config --cflags --libs dbus-1` `pkg-config --cflags --libs glib-2.0` `pkg-config --cflags --libs dbus-glib-1` `pkg-config --cflags --libs glib-2.0` `pkg-config --cflags --libs gio-2.0` `pkg-config --cflags --libs gio-unix-2.0` `pkg-config --cflags --libs gobject-2.0` `pkg-config --cflags --libs gthread-2.0` -o mdbus
}

in_progress_pkg() {
	gcc -Wall dbus-example-matthew.c `pkg-config --cflags --libs dbus-1` -o mdbus
}

# in_progress_details
# in_progress_pkg_full
in_progress_pkg
