#!/usr/bin/env bash

# SSH daemon
sudo service ssh start

echo "Dev C++"

# Copy github
cd ${HOME}
mkdir -p git-github && cd git-github && git clone https://github.com/doali/github.git && cd github && bash repo-pull-clone.sh
cd -

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
