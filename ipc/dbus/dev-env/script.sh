#!/usr/bin/env bash

# SSH daemon
sudo service ssh start

# Copy github
cd ${HOME}
mkdir -p git-github && cd git-github && git clone https://github.com/doali/github.git && cd github && bash repo-pull-clone.sh
cd -

# D-Bus # https://unix.stackexchange.com/questions/646934/d-bus-on-ubuntu-inside-a-docker-container
## TODO find a way to export the variable in bash session...
# cat >>/home/ubuntu/.bashrc <<EOF
# export DBUS_SESSION_BUS_ADDRESS=`dbus-daemon --fork --config-file=/usr/share/dbus-1/session.conf --print-address`
# EOF

exec "$@"

# TEST
# ====
#docker build --no-cache -t doali/dev-cpp:0.0.1 --build-arg UID=$(id -u) --build-arg PASSWORD=titi .
##docker build --no-cache -t doali/dev-cpp:0.0.1 --build-arg UID=$(id -u) .
#docker run -it -v $(pwd)/data:/volume/data:z doali/dev-cpp:0.0.1
#docker run -d -i -v $(pwd)/data:/volume/data:z -p 22000:22 doali/dev-cpp:0.0.1

# PASSWD generation for the user named ubuntu <== NOT USED !!
# ====
#echo "ubuntu" | openssl passwd -6 --stdin
#$1$Eld.Je18$Wotr7FIParpYolL8/0Pa0/ with command echo "ubuntu" | openssl passwd -1 --stdin
