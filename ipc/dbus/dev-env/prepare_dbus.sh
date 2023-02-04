#!/usr/bin/env bash

set -x

# source /home/ubuntu/.local/bin/source_dbus.rc

# echo ${DBUS_SESSION_BUS_ADDRESS}

set +x

source ~/.basrhc
cat ~/.local/bin/source_dbus.rc >>/etc/environment

cat >/dev/null