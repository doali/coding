# gtest 

google framework

## Installation

```bash
#!/usr/bin/env bash
# https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
sudo apt install googletest # creates /usr/src/googletest

readonly PATH_GTEST="/usr/src/googletest"
readonly DST_LIB="/usr/lib"

if [ -d ${PATH_GTEST} ]; then
  cd ${PATH_GTEST}
  sudo cmake CMakeLists.txt
  sudo make

  for i in "googlemock/gtest/libgtest.a" \
    "googlemock/gtest/libgtest_main.a" \
    "googlemock/libgmock.a" \
    "googlemock/libgmock_main.a"
  do
    echo "creating symlinks.."
    [ -f "${i}" ] && sudo ln -snf "${PATH_GTEST}"/"${i}" "${DST_LIB}"
  done

  cd -
else
  echo "error no ${PATH_GTEST} directory found"
fi
```

## Practise case

### Main folder

- `mkdir base-gtest` will contain 
    - C files describing our program
    - CPP files for our tests since gtest is for C++
    - building SHELL scripts


### C files (we want to test)

```bash
cat base-gtest/main.c
```

```c
#include <stdio.h>
#include <stdlib.h>

void scenario(int, int, int);
void usage(const char *);

/*
int main(int nbargs, char *argv[]) {
  if (nbargs == 4) {
    scenario(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  } else {

    usage(argv[0]);
  }

  return 0;
}
*/

void usage(const char *prog_name) {
  fprintf(stdout, "Usage %s <int> <int> <int>\n", prog_name);
}

/**
 * @return greatest number
 */
int compare(int a, int b, int c) {
  fprintf(stdout, "%s\n", __func__);
  int max = a;
  if (b > a) {
    max = b;
  }
  if (c > max) {
    max = c;
  }

  return max;
}

void scenario(int a, int b, int c) {
  fprintf(stdout, "%s\n", __func__);
  fprintf(stdout, "%d %d %d\n", a, b, c);
  int max = compare(a, b, c);
  fprintf(stdout, "max : %d\n", max);
}
```

#### Building

- for building we use the following script (do not forget to uncomment main function)

```bash
cat base-gtest/compile.sh
```

```bash
#!/usr/bin/env bash

readonly SRC_FILE="${1}"

if [ ! -z ${SRC_FILE} ]; then
  # -g : for gdb
  [ -f ${SRC_FILE} ] && gcc -g -o "${SRC_FILE%.*}" ${SRC_FILE}
else
  echo "Usage ${BASH_SOURCE[0]} <file_name.c>"
fi
```

- build like this : `./compile.sh main.c`

#### Running 

- run `main` executable like this : `./main 1 2 3`

### CPP file for testing

```bash
cat main_test.cpp
```

```cpp
#include <gtest/gtest.h>

// Trick to stop C++ from name-mangling
extern "C" {
#include "main.c"
}

// TEST is a macro
// TEST(TestCaseName, TestName)
// (!) _ are forbidden for names !!
// (!) TestCaseName must be unique
// (!) TestName must be unique
TEST(TestCaseNameCompare, TestNameMaxInFirst) {
  //  EXPECT_EQ is a macro
  EXPECT_EQ(3, compare(3, 1, 2));
}

TEST(Compare, MaxInFirst) { EXPECT_EQ(3, compare(3, 2, 1)); }

TEST(Compare, MaxInSecond) { EXPECT_EQ(3, compare(1, 3, 2)); }

TEST(Compare, MaxInThree) { EXPECT_EQ(3, compare(1, 2, 3)); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```

#### Building 

```bash
cat compile_test.sh
```

```bash
#!/usr/bin/env bash
g++ -o main_test main_test.cpp -L /usr/lib/ -I /usr/include/ -lgtest -lpthread
```

- where `main` were built using `./compile.sh main.c` (!) having `main` function commented !!

```text
#-L dir
#    To specify directories for the linker to search for the library files.
#-l library
#    This specifies a library to link with.
#-I dir
#    This specifies a directories for the compile to search for when looking for include files.
```

#### Running

- `./main_test`

```bash
[==========] Running 4 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TestCaseNameCompare
[ RUN      ] TestCaseNameCompare.TestNameMaxInFirst
compare
[       OK ] TestCaseNameCompare.TestNameMaxInFirst (0 ms)
[----------] 1 test from TestCaseNameCompare (0 ms total)

[----------] 3 tests from Compare
[ RUN      ] Compare.MaxInFirst
compare
[       OK ] Compare.MaxInFirst (0 ms)
[ RUN      ] Compare.MaxInSecond
compare
[       OK ] Compare.MaxInSecond (0 ms)
[ RUN      ] Compare.MaxInThree
compare
[       OK ] Compare.MaxInThree (0 ms)
[----------] 3 tests from Compare (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 4 tests.
```

##### Filter _Running_

./main_test --gtest_filter=Compare.MaxInFirst

```bash
Note: Google Test filter = Compare.MaxInFirst
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from Compare
[ RUN      ] Compare.MaxInFirst
compare
[       OK ] Compare.MaxInFirst (1 ms)
[----------] 1 test from Compare (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
```

## CODE

- [doali coding-c](https://github.com/doali/coding/tree/master/c/coding/ut/gtest/using_plain_gcc)

## Biblio

- [google github](https://github.com/google/googletest/blob/master/googletest/samples/sample1_unittest.cc)
- [tuto Erik Smistad](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/)
- [eatonphil](https://notes.eatonphil.com/unit-testing-c-code-with-gtest.html)
