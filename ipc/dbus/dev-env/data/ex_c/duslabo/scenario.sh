#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# Source code taken from
# https://github.com/duslabo/dbus-1/blob/master/dbus-2/server.cpp
# ------------------------------------------------------------------------------

scenario_1() {
    ./server &
    ./client
}

scenario_2() {
    ./server &
    local -r pid_server=$!
    echo "[${pid_server}] server running"
    sleep 2
    dbus-send --session --dest=test.foo.bar --print-reply --reply-timeout=500 / test.foo.Roll.Method
    sleep 1
    kill -s term ${pid_server}
    echo "[${pid_server}] server killed"
}

# WARNING !!! process server uses 98% of CPU !!!
compilation() {
    for exe in server client; do [ -f ${exe} ] && rm ${exe}; done
    make
}

compilation
scenario_2
