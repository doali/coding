#!/usr/bin/env bash

# ------------------------------------------------------------------------------
# https://www.softprayog.in/programming/d-bus-tutorial
# ------------------------------------------------------------------------------

compilation() {
	for exe in add-server add-client; do [ -f ${exe} ] && rm ${exe}; done
	make
}

info() {
	cat <<EOF
# In a terminal
#./add-server

# In another terminal
#./add-client 40 2

# In another terminal
#./add-client 2 40
EOF
}

compilation
info
