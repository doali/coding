# Compile

## Compilation

- [univ lille](https://www.fil.univ-lille1.fr/~sedoglav/PDC2/main006.html#sec9)
- [pratique](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)

## Linker

- [stackoverflow](https://stackoverflow.com/questions/14163208/how-to-link-c-object-files-with-ld)

## Read file objects

_First install `bvi` with the command line `sudo apt install bvi`_

Assuming that we did as follow

- `gcc -c hello.c` => file object `hello.o` is generated

then, we can read `hello.o` file like this `bvi hello.o`

### Example

[bvi_gdb_main](img/bvi_gdb_main.png)


## Biblio

- [renenyffengger](https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index)
- [geeks for geeks](https://www.geeksforgeeks.org/compiling-with-g-plus-plus/)
- [useful macro gnu](https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html)
- [ELF](https://refspecs.linuxbase.org/elf/gabi4+/ch4.intro.html)
