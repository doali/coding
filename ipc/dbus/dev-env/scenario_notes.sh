#!/usr/bin/env bash

# ==============================================================================
# Docker : build, run and connect from ssh
# A few notes as well...
# ==============================================================================

# ------------------------------------------------------------------------------
# Docker build
# ------------------------------------------------------------------------------
docker build --no-cache -t doali/dev-cpp:0.0.1 --build-arg UID=$(id -u) --build-arg PASSWORD=titi .
##docker build -t doali/dev-cpp:0.0.1 --build-arg UID=$(id -u) --build-arg PASSWORD=titi .
##docker build --no-cache -t doali/dev-cpp:0.0.1 --build-arg UID=$(id -u) .

# ------------------------------------------------------------------------------
# Docker run
# ------------------------------------------------------------------------------
#docker run -it -v $(pwd)/data:/volume/data:z doali/dev-cpp:0.0.1
docker run -d -i -v $(pwd)/data:/volume/data:z -p 22000:22 doali/dev-cpp:0.0.1

# ------------------------------------------------------------------------------
# ssh
# ------------------------------------------------------------------------------
#ssh -p 22000 ubuntu@localhost

# ------------------------------------------------------------------------------
# d-bus
# ------------------------------------------------------------------------------
#source ~/.bashrc
#dbus-monitor

# ------------------------------------------------------------------------------
# PASSWD generation for the user named ubuntu <== NOT USED !!
# ------------------------------------------------------------------------------
#echo "ubuntu" | openssl passwd -6 --stdin
#$1$Eld.Je18$Wotr7FIParpYolL8/0Pa0/ with command echo "ubuntu" | openssl passwd -1 --stdin
