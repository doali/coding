# gcov

GNU COVerage

```bash
gcov is a test coverage program.  Use it in concert with GCC to analyze your programs to help create more efficient,
       faster running code and to discover untested parts of your program.  You can use gcov as a profiling tool to help discover
       where your optimization efforts will best affect your code.  You can also use gcov along with the other profiling tool,
       gprof, to assess which parts of your code use the greatest amount of computing time.
```    

## In a word

- test coverage program
- profiler
- gcov works only on code compiled with GCC
    - `-fprofile-arcs -ftest-coverage` expected options
- creates a logfile called sourcefile.gcov 
    - which indicates how many times each line of a source file sourcefile.c has executed

## Features

```bash
gcov should be run with the current directory the same as that when you invoked the compiler.  Otherwise it will not be
       able to locate the source files.  gcov produces files called mangledname.gcov in the current directory.  These contain the
       coverage information of the source file they correspond to.
```

```bash
Note that GCC can completely remove the bodies of functions that are not needed -- for instance if they are inlined
       everywhere.  Such functions are marked with -, which can be confusing.  Use the -fkeep-inline-functions and
       -fkeep-static-functions options to retain these functions and allow gcov to properly show their execution_count.
```

```bash
When using gcov, you must first compile your program with two special GCC options: -fprofile-arcs -ftest-coverage.  This
       tells the compiler to generate additional information needed by gcov (basically a flow graph of the program) and also
       includes additional code in the object files for generating the extra profiling information needed by gcov.  These
       additional files are placed in the directory where the object file is located.
```

### Understanding files

- `.gcda`
    - data file
    - needs `-fprofile-arcs` compile option to be created
    - for each source file, we get a .gcda file
- `.gcno`
    - data file
- `.gcov`
    - human readable
    - one .gcov file per .gcda file
    - contains the : separated fields along with program source code.  
        - The format is `<execution_count>:<line_number>:<source line text>`
            - Unexecuted lines are marked ##### or =====,
            - unexecuted blocks are marked $$$$$ or %%%%%

## Scenario

### C file

```c
#include <stdio.h>
#include <stdlib.h>

void scenario(int, int, int);
void usage(const char *);

int main(int nbargs, char *argv[]) {
  if (nbargs == 4) {
    scenario(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
  } else {

    usage(argv[0]);
  }

  return 0;
}

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

### Building

- `gcc -o main -fprofile-arcs -ftest-coverage main.c`

> `-fprofile-arcs -ftest-coverage` are needed !! \
> `main.gcno` has been created

```bash
file main.gcno
```
which returns

```bash
main.gcno: GCC gcno coverage (-ftest-coverage), version A.5
```

### Run (our compiled program)

- now, we need to **run** our program : `./main 1 2 3` to feed `gcov.gcda`

> file main.gcda created

```bash
file main.gcda
```

which returns

```bash
> file main.gcda 
main.gcda: GCC gcda coverage (-fprofile-arcs), version A.5
```

### Run `gcov`

- `gcov -b main.c`

which outputs

```bash
File 'main.c'
Lines executed:81.82% of 22
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:75.00% of 8
Creating 'main.c.gcov'
```

> `main.c.gcov` created

### Outcomes

- `cat main.c.gcov`

```text
-:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:1
-:    0:Programs:1
-:    1:#include <stdio.h>
-:    2:#include <stdlib.h>
-:    3:
-:    4:void scenario(int, int, int);
-:    5:void usage(const char *);
-:    6:
function main called 1 returned 100% blocks executed 80%
1:    7:int main(int nbargs, char *argv[]) {
1:    8:  if (nbargs == 4) {
        branch  0 taken 100% (fallthrough)
          branch  1 taken 0%
          1:    9:    scenario(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
        call    0 returned 100%
          -:   10:  } else {
            -:   11:
#####:   12:    usage(argv[0]);
              call    0 never executed
              -:   13:  }
      -:   14:
        1:   15:  return 0;
      -:   16:}
      -:   17:
      function usage called 0 returned 0% blocks executed 0%
#####:   18:void usage(const char *prog_name) {
#####:   19:  fprintf(stdout, "Usage %s <int> <int> <int>\n", prog_name);
  call    0 never executed
#####:   20:}
  -:   21:
  -:   22:/**
            -:   23: * @return greatest number
            -:   24: */
  function compare called 1 returned 100% blocks executed 100%
  1:   25:int compare(int a, int b, int c) {
1:   26:  fprintf(stdout, "%s\n", __func__);
     call    0 returned 100%
       1:   27:  int max = a;
1:   28:  if (b > a) {
       branch  0 taken 100% (fallthrough)
         branch  1 taken 0%
         1:   29:    max = b;
       -:   30:  }
1:   31:  if (c > max) {
       branch  0 taken 100% (fallthrough)
         branch  1 taken 0%
         1:   32:    max = c;
       -:   33:  }
     -:   34:
       1:   35:  return max;
     -:   36:}
     -:   37:
     function scenario called 1 returned 100% blocks executed 100%
     1:   38:void scenario(int a, int b, int c) {
1:   39:  fprintf(stdout, "%s\n", __func__);
     call    0 returned 100%
       1:   40:  fprintf(stdout, "%d %d %d\n", a, b, c);
     call    0 returned 100%
       1:   41:  int max = compare(a, b, c);
     call    0 returned 100%
       1:   42:  fprintf(stdout, "max : %d\n", max);
     call    0 returned 100%
       1:   43:}
```

### `gcov` a few options

```bash
-n
--no-output
   Do not create the gcov output file.
```

```bash
-d
--display-progress
   Display the progress on the standard output.
```

```bash
-b
--branch-probabilities
   Write branch frequencies to the output file, and write branch summary info to the standard output.  This option allows
   you to see how often each branch in your program was taken.  Unconditional branches will not be shown, unless the -u
   option is given.
```

## Extra

- `gprof` : profiling tool which analyses computing time
- `gtest` : google test tools

## Biblio

- [gcov lcov](https://www.youtube.com/watch?v=D9LXwfg_tqI)
- [cpp](https://www.youtube.com/watch?v=0Pdl0oIwCgw)
- [googletest](https://medium.com/@naveen.maltesh/generating-code-coverage-report-using-gnu-gcov-lcov-ee54a4de3f11)
- `man gcov`
