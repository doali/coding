#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# https://unix.stackexchange.com/questions/646934/d-bus-on-ubuntu-inside-a-docker-container
# - export the variable DBUS_SESSION_BUS_ADDRESS in bash session...
# ------------------------------------------------------------------------------

# SSH daemon
sudo service ssh start

# Copy github
cd ${HOME}
mkdir -p git-github && cd git-github && git clone https://github.com/doali/github.git && cd github && bash repo-pull-clone.sh
cd -

# TODO find a way to export the variable in bash session...
cat >>/home/ubuntu/.bashrc <<EOF
export DBUS_SESSION_BUS_ADDRESS=`dbus-daemon --fork --config-file=/usr/share/dbus-1/session.conf --print-address`
EOF

exec "$@"
