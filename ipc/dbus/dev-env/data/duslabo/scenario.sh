#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# Source code taken from
# https://github.com/duslabo/dbus-1/blob/master/dbus-2/server.cpp
# ------------------------------------------------------------------------------

make
./server &
./client

# WARNING !!! process server uses 98% of CPU !!!
