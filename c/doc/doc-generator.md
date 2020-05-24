# Doxygen

## Install

- `sudo apt update`
- `sudo apt install -y doxygen`

## Generate

_Let us assume that we have `.c`, `.h` files in the current directory._

- `tree`

```bash
.
├── array-2.c
```

- `doxygen -g` creates a Doxyfile which contains settings

```text
> doxygen -g


Configuration file `Doxyfile' created.

Now edit the configuration file and enter

  doxygen Doxyfile

to generate the documentation for your project
```

- `doxygen` generates documentation and more precisely two folders, html and latex

```bash
.
├── array-2.c
├── Doxyfile
├── html
└── latex
```

## Browsing the doc

- `firefox --new-tab html/index.html`

### Important `\file [<file_name>]`

```c
/**
 * \file array-2.c
 * \brief Arrays
 */
```

> These two lines indicates doxygen to read this file and generate its documentation.

## Biblio

- [linux.m2osw](https://linux.m2osw.com/doxygen-does-not-generate-documentation-my-c-functions-or-any-global-function#comment-1803)
- [ranvir](https://ranvirsinghprojects.wordpress.com/2016/07/08/creating-documentation-using-doxygen-in-ubuntu/)
- [doxygen.nl](http://www.doxygen.nl/manual/docblocks.html)
- [ift.ulaval](http://www2.ift.ulaval.ca/~eude/Gif-1003/Documents/Initiation-a-Doxygen-pour-C-Cpp.pdf)
