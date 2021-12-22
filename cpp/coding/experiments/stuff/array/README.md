# Tableaux...

_juste pour observer des implémentations différentes de tableaux..._

- observer la consommation mémoire...

## Compilation

- `gcc -Wall -o tab_c tab_c.c`
- `g++ -Wall -o tab_cpp tab_cpp.cpp`
- `g++ -std=gnu++2a -Wall -o tab_cpp_modern tab_cpp_modern.cpp`

> `-std=gnu++2a` est utilisé pour la déclaration de `int i` dans la boucle `for`
> J'ai un peu trouvé au hasard (influence de Go)...

## Valgrind

- `valgrind ./tab_c`
- `valgrind ./tab_cpp`
- `valgrind ./tab_cpp_modern`
