#!/usr/bin/env bash

readonly CPP_FILE=$1
readonly STYLE=LLVM # Google, Chromium, Mozilla, WebKit

clang-format -i -style=LLVM ${CPP_FILE}
