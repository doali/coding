#!/usr/bin/env bash
docker run -d -i -v $(pwd)/data:/volume/data:z -p 22000:22 doali/dev-cpp:0.0.1
