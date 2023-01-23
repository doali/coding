#!/usr/bin/env bash
docker build --no-cache -t doali/dev-cpp:0.0.1 --build-arg UID=$(id -u) --build-arg PASSWORD=titi .
