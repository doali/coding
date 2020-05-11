# `typedef`

## Basic data types

```c
typedef <type> alias;
```

```c
/* Parameterizes a C type.                                                   */
/* When the program requires a larger f-p format, simply change the typedef. */
typedef float REAL;
/* Variables x1 and x2 have the same type.                                   */
REAL x1;
```

## `struct`

```c
typedef struct { ... } alias_1, *alias_2, ...;
```

> `alias_2` is an alias for `struct *`

```c
/* Provides a common C idiom to avoid writing "struct" repeatedly. */
/* anonymous struct                                                */
typedef struct {int a; int b;} S, *PS;
/* Variables ps1 and ps2 have the same type.                       */
PS ps1;
S* ps2;
```

## Arrays
 
```
typedef <type> ARRAY_LABEL[CONST_SIZE];
```

```c
/* typedef with array */
typedef int ARR_T[10];
ARR_T a1;
int a2[10];   /* same as a1 */
printf("sizeof(a1) = %zu\n", sizeof(a1));   // 40 bytes
printf("sizeof(a2) = %zu\n", sizeof(a2));   // 40 bytes
```

## Pointers

```c
typedef <type> *pName;
```

```c
/* typedef with pointer */
int i=0;
typedef int * PTR_TO_INT;
PTR_TO_INT pi = &i;
```

## Function pointers

```c
typedef <type>(*alias)([type])
```

```c
/* typedef with function pointer                                                */
/* FP is a synonym for a pointer to a function that neither takes nor returns a */
/* value.                                                                       */
typedef void (*FP)(void);
```

- [cppreference](http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/c/language/typedef.html)

## `enum`

```c
/*
 * https://en.cppreference.com/w/c/language/enum
 */

#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
// Here we use typedef !!
// - we define aliases !! <= IMPORTANT
// -----------------------------------------------------------------------------
typedef enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
} alias_direction,    /* alias_direction is an ALIAS */
    *pAliasDirection; /* alias_direction is an ALIAS */

enum Label {
  LABEL_10 = 10,
  LABEL_11,
} e_label,   /* e_label is a VARIABLE !! */
    *pLabel; /* here, no doubt that pLabel is a VARIABLE */

int main(void) {
  // ---------------------------------------------------------------------------
  // e_label lab_10 = LABEL_10; // expression can not be assigned !! e_label is
  // a variable
  e_label = LABEL_10; // assignement of variable : OK
  pLabel = &e_label;  // OK

  printf("%d\n", e_label);
  printf("%d\n", *pLabel);

  // ---------------------------------------------------------------------------
  alias_direction dir_down = DOWN; // declaration : OK
  pAliasDirection pDirUp =
      &dir_down; // declaration : OK (pDirUp is enum Direction*)

  printf("%d\n", dir_down);
  printf("%d\n", *pDirUp);
}
```

- [enum_warning](https://github.com/doali/coding/blob/master/c/coding/var/enum/enum_warning.c)

## Biblio

- [cppreference typedef](https://en.cppreference.com/w/c/language/typedef)
