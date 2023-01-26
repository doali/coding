# Qt, qmake vers cmake

Les projets réalisés avec Qt Creator utilisent `qmake` et un fichier de configuration `.pro`

Le lien suivant explique comment compiler avec `cmake` plutôt que `qmake`

> [stackoverflow qmake cmake](https://stackoverflow.com/questions/43763416/how-to-convert-qmake-to-cmake)


## `qmake`

> git-github/coding/cpp/coding/gui/projQt/oc_cpp_qt/qmake_empty/test

```bash
.
├── fenetre.cpp
├── fenetre.h
├── main.cpp
├── test.pro
└── test.sh
```

**File `.pro`**

```bash
QT += widgets
TARGET = progress_bar
CONFIG += debug
SOURCES += \
    fenetre.cpp \
    main.cpp

HEADERS += \
    fenetre.h
```

**Compilation**

```bash
#!/usr/bin/bash

# ------------------------------------------------------------------------------
# How to use qmake and make
# https://doc.qt.io/qt-6/qmake-tutorial.html 
# ------------------------------------------------------------------------------
# dim. 27 nov. 2022 14:06:04 CET
# ------------------------------------------------------------------------------

# scenario custom and silly
#qmake -o titi_makefile test.pro
#make -f titi_makefile # need to specify makefile name since it is not Makefile
#make -f titi_makefile clean # to removed all created file using make

# scenario
qmake
make
make clean
```

## `cmake`

> git-github/coding/cpp/coding/pattern/dp_state/experiments

```bash
.
├── CMakeLists.txt
├── lib
│   ├── CMakeLists.txt
│   ├── fsm.cpp
│   └── fsm.hpp
└── main.cpp
```

**File `CMakeLists.txt`**

```bash
cmake_minimum_required(VERSION 3.15)

project(StateMachine VERSION 1.0)

add_executable(sm main.cpp)
target_link_libraries(sm PUBLIC fsm)
add_subdirectory(lib)

message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
#set(CMAKE_CXX_FLAGS "-ggdb -Wall")
message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")

include_directories(${CMAKE_SOURCE_DIR}/lib) # avoid writting #include "lib/fsm.hpp" in main.cpp
message("CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
```

**Execution**

```bash
#!/usr/bin/bash

readonly BUILD=build
readonly SRC=src
readonly EXE=sm

# ------------------------------------------------------------------------------
[ -d ${BUILD} ] && rm -rf ${BUILD}
mkdir ${BUILD}

# ------------------------------------------------------------------------------
cd ${BUILD}

cmake ../${SRC}
make

# ------------------------------------------------------------------------------
./${EXE}
```
