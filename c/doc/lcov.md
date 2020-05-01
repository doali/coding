# gtest -> gcov -> lcov 

`gtest` a testing framework developed by the Testing Technology team with Google's specific requirements and constraints in mind

```bash
gcov (1)             - coverage testing tool
lcov (1)             - a graphical GCOV front-end
```

## Study case

We refering to [gcov](https://github.com/doali/coding/blob/master/c/doc/gcov.md) and especially [gtest](https://github.com/doali/coding/blob/master/c/doc/gtest.md) that we keep on going with

> The below example can be done with the following script  \
> [gtest_scenario.sh](https://github.com/doali/coding/blob/master/c/coding/ut/g_test_cov/gtest_scenario.sh)

### Compilation

according to what has been done in [gtest](https://github.com/doali/coding/blob/master/c/doc/gtest.md) 

```bash
.
├── compile.sh
├── compile_test.sh
├── gtest_scenario.sh
├── main.c
└── main_test.cpp
```

```bash
g++ -fprofile-arcs -ftest-coverage \
  -o main_test main_test.cpp \
  -L /usr/lib/ -I /usr/include/ \
  -lgtest -lpthread
```

### Run program

this command can be run from `compile_test.sh` which leads to this new tree

```bash
.
├── compile.sh
├── compile_test.sh
├── gtest_scenario.sh
├── main.c
├── main_test
├── main_test.cpp
└── main_test.gcno
```

one's can notice the new file `main_test.gcno` (basic block construction and line numbers) (some more explanations here [gcov](https://github.com/doali/coding/blob/master/c/doc/gcov.md))

> Next, we must **run** the executable `./main_test`

Indeed, this will generate files required for coverage report generation

First, on the output we can see gtest outcomes

```text
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
[       OK ] Compare.MaxInSecond (1 ms)
[ RUN      ] Compare.MaxInThree
compare
[       OK ] Compare.MaxInThree (0 ms)
[----------] 3 tests from Compare (1 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 4 tests.
```

and new files

```bash
.
├── compile.sh
├── compile_test.sh
├── gtest_scenario.sh
├── main.c
├── main_test
├── main_test.cpp
├── main_test.gcda
└── main_test.gcno
```

especially `main_test.gcda` (profiling and coverage information)

### `gcov` or else profiling

- `gcov -b main_test.cpp`

which outputs

```bash
File 'main_test.cpp'
Lines executed:100.00% of 10
Branches executed:61.90% of 84
Taken at least once:30.95% of 84
Calls executed:59.52% of 126
Creating 'main_test.cpp.gcov'

File '/usr/include/gtest/internal/gtest-internal.h'
Lines executed:85.71% of 7
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
Calls executed:81.25% of 32
Creating 'gtest-internal.h.gcov'

File '/usr/include/c++/7/iostream'
Lines executed:100.00% of 1
No branches
Calls executed:100.00% of 2
Creating 'iostream.gcov'

File '/usr/include/gtest/gtest-printers.h'
Lines executed:0.00% of 26
Branches executed:0.00% of 8
Taken at least once:0.00% of 8
Calls executed:0.00% of 15
Creating 'gtest-printers.h.gcov'

File '/usr/include/gtest/gtest.h'
Lines executed:61.11% of 18
Branches executed:25.00% of 8
Taken at least once:12.50% of 8
Calls executed:29.41% of 17
Creating 'gtest.h.gcov'

File '/usr/include/gtest/internal/gtest-port.h'
Lines executed:77.78% of 9
Branches executed:66.67% of 12
Taken at least once:33.33% of 12
Calls executed:57.14% of 7
Creating 'gtest-port.h.gcov'

File 'main.c'
Lines executed:47.06% of 17
Branches executed:100.00% of 4
Taken at least once:100.00% of 4
Calls executed:16.67% of 6
Creating 'main.c.gcov'

File '/usr/include/gtest/gtest-message.h'
Lines executed:100.00% of 1
No branches
Calls executed:100.00% of 1
Creating 'gtest-message.h.gcov'

File '/usr/include/c++/7/bits/ios_base.h'
Lines executed:100.00% of 2
No branches
No calls
Creating 'ios_base.h.gcov'
```

```bash
tree
```

```bash
.
├── compile.sh
├── compile_test.sh
├── gtest.h.gcov
├── gtest-internal.h.gcov
├── gtest-message.h.gcov
├── gtest-port.h.gcov
├── gtest-printers.h.gcov
├── gtest_scenario.sh
├── ios_base.h.gcov
├── iostream.gcov
├── main.c
├── main.c.gcov
├── main_test
├── main_test.cpp
├── main_test.cpp.gcov
├── main_test.gcda
└── main_test.gcno
```

```bash
gcov creates a logfile called sourcefile.gcov which indicates how many times each line of a source file sourcefile.c has
executed.  You can use these logfiles along with gprof to aid in fine-tuning the performance of your programs.  gprof
gives timing information you can use along with the information you get from gcov.
```

> `.gcov` files has been generated \
> those are our coverage reports

### `lcov` 

```bash
collects line, function and branch coverage data for multiple source files and creates HTML pages containing the source code annotated with coverage information.
```

- `lcov --capture --directory . --output-file main_test_coverage.info`

> `--capture` capture coverage data
> `--directory` capture counts for a user space program
> `--output-file` write data to tracefile instead of stdout

```bash
Capturing coverage data from .
Found gcov version: 7.5.0
Scanning . for .gcda files ...
Found 1 data files in .
Processing main_test.gcda
Finished .info-file creation
```

```bash
tree
```

```bash
.
├── compile.sh
├── compile_test.sh
├── gtest_scenario.sh
├── main.c
├── main_test
├── main_test_coverage.info
├── main_test.cpp
├── main_test.gcda
└── main_test.gcno
```

eveything has been gathered in the file `.info`, `main_test_coverage.info` which is a coverage report made with `.gcno` and `.gcda` files.

### `genhtml`

- `genhtml main_test_coverage.info --output-directory main_test_report`

generates all needed files in `main_test_report` folder

- `firefox --new-tab main_test_report/index.html`

## Biblio

- [gcov lcov](https://www.youtube.com/watch?v=D9LXwfg_tqI)
- [cpp](https://www.youtube.com/watch?v=0Pdl0oIwCgw)
- [tuto youtube](https://www.youtube.com/watch?v=D9LXwfg_tqI)
- `man lcov`
