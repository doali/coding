#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# Exemple repris
# https://unix.stackexchange.com/questions/646934/d-bus-on-ubuntu-inside-a-docker-container
# ------------------------------------------------------------------------------
export DBUS_SESSION_BUS_ADDRESS=`dbus-daemon --fork --config-file=/usr/share/dbus-1/session.conf --print-address`
#dbus-send --print-reply --session --dest=com.testservice /testservice com.testservice.Exit
