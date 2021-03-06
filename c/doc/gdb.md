# GDB _GNU Debugger_

## Scenario

- Ne pas oublier d'ajouter le flag :`-ggdb` lors de la compilation avec `gcc` ou `g++`

```bash
       -g  Produce debugging information in the operating system's native format (stabs, COFF, XCOFF, or DWARF).  GDB can work
           with this debugging information.
```

```bash
       -ggdb
           Produce debugging information for use by GDB.  This means to use the most expressive format available (DWARF, stabs,
           or the native format if neither of those are supported), including GDB extensions if at all possible.
```

```text
Scénario
1 $: gdb ./main (lancement de GDB sur l'exécutable main : dans terminal)
2 gdb: b 8 (break point à la ligne 8: dans gdb)
3 gdb: r 1 456 78 (lancement de l'exécutable main avec des arguments : dans gdb) 
4 gdb: refresh main.c (ouvre le fichier source et positionne des infos : dans gdb)
5 gdb: n (passer à la prochaine ligne d'instruction : dans gdb)
6 gdb: c (poursuivre le programme (stoppé) jusqu'au prochain breakpoint : dans gdb)
```

### `gdb` with arguments

```bash
gdb --args executablename arg1 arg2 arg3
```

## CODE

- [compile.sh](https://github.com/doali/coding/blob/master/c/coding/ut/gtest/compile.sh)

## Captures

![gdb disassemble](img/disassemble-next-line.png)
![gdb disassemble deeper](img/disassemble-next-line_2.png)
![gdb Crt + x + 2](img/disassemble-next-line.png)

## Biblio

- `man gdb`
- [sourceware](https://sourceware.org/gdb/current/onlinedocs/gdb/Memory.html)
- [brown edu](https://cs.brown.edu/courses/cs033/docs/guides/gdb.pdf)
- [gdb Crt + x + 2](https://stackoverflow.com/questions/1902901/show-current-assembly-instruction-in-gdb)
