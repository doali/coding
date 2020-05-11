# Hello World !!

## code

```c
#include <stdio.h>

/* Compilation
 * gcc -o hello hello.c
 */

/* Execution
 * ./hello
 */

void do_something() {
  printf(__func__);
  printf("\n");
  printf("Hi doing something\n");
}

int main() {
  printf(__func__);
  printf("\n");

  do_something();

  return 0;
}
```

## `Makefile`

```Makefile
all: hello.exe

hello.exe: hello.o
	 gcc -o hello.exe hello.o

hello.o: hello.c
	 gcc -c hello.c

clean:
	 rm hello.o hello.exe
```

- `make`
- `make all`
- `make clean`

## cmd

```bash
.
├── cmd_as
├── cmd_cpp
├── cmd_gcc
├── cmd_ld
├── cmd_ldd
├── cmd_nm
├── cmd_scenario
├── cmp_cpp
├── hello.c
└── Makefile
```

- [doali code](coding/c/coding/hello)

## Biblio

- [ufsc](https://lisha.ufsc.br/teaching/os/exercise/hello.html)
- [ntu](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)
