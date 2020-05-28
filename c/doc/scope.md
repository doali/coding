# Scope

Portée d'une variable, fonction, type structuré ...définie lors de la déclaration.

- [cppreference scope](https://en.cppreference.com/w/c/language/scope)

## Portée locale

Variable dite locale

- définie entre `{` et `}` (définissant un bloc)
- portée de bloc

> Blocs pouvant être imbriqués \
> Variable intérieure à un bloc, de même nom qu'une variable extérieure au bloc, masque la variable extérieure

## Portée de fonction

Variable visible uniquement dans la fonction

### Exemple

- [goto.c](https://github.com/doali/coding/blob/master/c/coding/var/goto.c)
- [zestedesavoir exemple cas utilisation](https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/5155_la-gestion-derreur-2/)

## Portée globale

_On dit encore, portée de programme_

Variable dite globale

- déclarée en dehors de toute fonction
- visible dans TOUS les fichiers (qui constituent le progamme) (modulo, include .h, extern...)

### Exemple

- [global-scope](https://github.com/doali/coding/blob/master/c/coding/var/global-scope.c)
- [global.c](https://github.com/doali/coding/blob/master/c/coding/var/scope/global.c)
- [global_h.h](https://github.com/doali/coding/blob/master/c/coding/var/scope/global_h.h)
- [global_func.c](https://github.com/doali/coding/blob/master/c/coding/var/scope/global_func.c)


## Portée de fichier

_Translation unit (portée de fichier), introduite par `static`_

## `static`

- [static_global.c](https://github.com/doali/coding/blob/master/c/coding/var/scope/static_global.c)

### Variables

> Static variables should not be declared inside structure. \
> The reason is C compiler requires the entire structure elements to be placed together (i.e.) \
> memory allocation for structure members should be contiguous.

- [statckoverflow](https://stackoverflow.com/questions/572547/what-does-static-mean-in-c)
- [geeksforgeeks variable](https://www.geeksforgeeks.org/static-variables-in-c)

### functions 

> In C, functions are global by default. \
> The “static” keyword before a function name makes it static. \
> Unlike global functions in C, access to static functions is restricted to the file where they are declared.

- [geeksforgeeks function](https://www.geeksforgeeks.org/what-are-static-functions-in-c/)

## Lifetime

- [cppreference](https://en.cppreference.com/w/c/language/lifetime)

## `auto`, `static`, `register`, `volatile`, `extern`

![storage classes in c](img/Storage-Classes-In-C.png)

> image from [geeksforgeeks](https://www.geeksforgeeks.org/storage-classes-in-c/)

- [casteyde christian](http://casteyde.christian.free.fr/cpp/cours/online/x1432.html)

### `auto`

```text
auto: This is the default storage class for all the variables declared inside a function or a block. Hence, the keyword auto is rarely used while writing programs in C language.
```

> from [geeksforgeeks](https://www.geeksforgeeks.org/storage-classes-in-c/)

### `extern`

- [geeksforgeeks](https://www.geeksforgeeks.org/understanding-extern-keyword-in-c/)

#### for variables
```c
extern int var;
```

- declaration only, no memory allocation

```c
int var;
```
- declaration + (definition => memory allocation, stack)

#### for functions

- `extern` is implicite !!

## Biblio

- [Tony Zhang](https://www.amazon.fr/Langage-C-Tony-Zhang/dp/2744015180)
- [cppreference scope](https://en.cppreference.com/w/c/language/scope)
