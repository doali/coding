# Macro

_Elles interviennent lors de la phase de précompilation et réalise une `substitution` (chercher / remplacer)._

## Génération

Etant donné un fichier source `main.c`

- `cpp main.c >main.i`

ou encore

- `gcc -E main.c >main.i`

> on peut aussi remplacer la redirection `>` par l'option `-o` \
> `gcc -E -o main.i main.c` \
> `cpp -o main.i main.c`

### Système

Plus de 300 macros sont déjà définies (347 sur mon système `gcc -v` renvoie entre autre `gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)`) que l'on peut observer via la commande `gcc -x c /dev/null -dM -E`

```bash
gcc -x c /dev/null -dM -E
```

> `-x c` indique que l'on veut compiler du `c` car le fichier `/dev/null` n'indique pas son extension \
> `-dM` stands for *Dump Macros* \
> `-E` pour ne pas lancer la compilation ni l'édition des liens \

(!) les noms des macros systèmes commencent par `__` par conséquent, la règle est de ne pas définir de symboles de macro commençant par un double underscore !!

### Macros prédéfinies utiles

- `__FILE__` : nom du fichier en cours
- `__LINE__` : numéro de ligne en cours
- `__func__` : nom de la fonction en cours
- `__TIME__` : heure de la compilation
- `__DATE__` : date de la compilation

## Macro de symboles

Elles introduisent des symboles, constantes des "include guards"

- `#define <SYMBOLE> <definition>`

> `<SYMBOLE>` le plus souvent en MAJUSCULE \
> `<definition>` introduit ce que l'on souhaite !

### Constante

```c
#define MAX_BUFF 1024 // définition d'une constante
```

### `include guards`

```c
#ifndef _MAIN_H
#define _MAIN_H

/*
 * Tout le code doit-être enveloppé ainsi !!
 */

#endif
```

> Trick à utiliser pour s'assurer d'inclure **une seule fois** le fichier !

## Macro de fonctions

Elles introduisent des fonctions

### Syntaxe

```c
#define NOM_MACRO(PAR_A, PAR_B) \
  int c = PAR_A + PAR_B; 
```

### Fonctions

```c
#define FREE(P)                                                                \
  do {                                                                         \
    free(P);                                                                   \
    P = NULL;                                                                  \
  } while (0)

#endif
```

- [doali macro.h](https://github.com/doali/coding/blob/master/c/coding/macro/basics/macro.h)

```c
#define LINE_BREAK(NB_C)                                                       \
  do {                                                                         \
    for (int i = 0; i < NB_C; ++i) {                                           \
      printf("%c", '-');                                                       \
    }                                                                          \
    printf("\n");                                                              \
  } while (0)
```

- [doali main.c](https://github.com/doali/coding/blob/master/c/coding/macro/basics/main.c)

> Il est important de ne pas mettre de `;` en fin de ligne `} while (0)` \
> cela permettra d'homogénéiser l'utilisation des macros en ajoutant un `;` dans le code

```c
FREE(buff);
```

```c
LINE_BREAK_80;
```

> On peut ainsi ajouter lors de l'utilisation de la macro un `;` terminant l'instruction

## Opérateurs

### `#`

Pour envelopper de `"`

```c
#define SYMBOLE_2_STR(X) (#X)
```

### `##`

Pour la concaténation

```c
#include <stdio.h>

#define CONCAT(A, B) A##B
#define WRAPP(X) #X
#define TO_STR(X)                                                              \
  WRAPP(X) // permet l'expanding lors de la précompilation
           // et produit l'effet souhaite !! (IMPORTANT) <====

int main(int argc, char **argv) {
  const char *CONCAT(str, _0) = "bof";
  printf("str_0, on sait qu'il existe, mais %s\n", str_0); // HORREUR !!

  /*
   * ----------------------------------------------------------------
   * POINT IMPORTANT (imbrication de macros, expanding, évaluation...
   * ----------------------------------------------------------------
   */
  printf("%s\n", TO_STR(CONCAT(MACRO, _A_GOGO))); // avec WRAPP(X) => :-)

  return 0;
}
```

## Exemples

Quelques exemples de code...

```c
#include <stdio.h>

#define LINE_BREAK printf("\n")

#define WRAPP(W) #W
// permet d'envelopper W de guillemets
// fonctionne
// - uniquement dans la définition de la macro
// - sur un PARAMETRE (pas de #MON_AUTRE_MACRO(A, B) <= marchera pas !!)

void notes(void) {
  printf(__func__);

  // LINE_BREAK;
  // printf(""); // OK mais warnings
  /*
   * gcc -c notes
   *
   * renvoie en sortie
   * ==================================
   * note-printf.c: In function ‘notes’:
   * note-printf.c:14:10: warning: zero-length gnu_printf format string
   * [-Wformat-zero-length] printf("");
   * ==================================
   * Cette instruction ne sert évidemment à rien et le compilateur nous
   * l'indique !
   */

  /*
  LINE_BREAK;
  printf(""
         ""
         ""); // OK mais warnings (compilateur indique que la chaine est
  vide)
         */

  LINE_BREAK;
  printf(""
         "\n"); // On peut ajouter des guillements les uns à la suite

  LINE_BREAK;
  printf(""
         "a"
         ""); // OK

  LINE_BREAK;
  printf(WRAPP(mot));

  LINE_BREAK;
  printf("WORD>" WRAPP(mot)); // Du coup, on peut utiliser
                              // l'opérateur # dans la définition des macros
                              // et le placer dans un printf :-)

  LINE_BREAK;
  printf("START>" WRAPP(mot) "<END\n");

  LINE_BREAK;
  printf("Look at the code\n");
}
```

### Expanding, ajouter des niveaux !!

```c
#include <stdio.h>

#define WRAPP(X) (#X)             // permet d'envelopper X de guillements
#define CONS_LIB_NAME(X) lib##X.a // malgré le . on a une concaténation :-)

//#define TO_STR(X) #X // pas l'effet souhaité lors d'imbrication de macros...
#define TO_STR(X)                                                              \
  WRAPP(X) // permet l'expanding lors de la précompilation
           // et produit l'effet souhaite !! (IMPORTANT) <====

int main(int argc, char **argv) {
  printf("%s\n", WRAPP(COUCOU));

  /*
   * ----------------------------------------------------------------
   * POINT IMPORTANT (imbrication de macros, expanding, évaluation...
   * ----------------------------------------------------------------
   * LE PROBLEME
   * ----------------------------------------------------------------
   */

#define TO_STR(X)                                                              \
#X // RM on redefinit ici pour l'exercice... mais à ne pas faire

  printf("%s\n", TO_STR(CONS_LIB_NAME(titi))); // sans WRAPP(X) => :-(

  /* On obtient en sortie
   *
   * CONS_LIB_NAME(titi)
   *
   * ce que l'on ne veut pas... il manque l'expanding !!
   * Pour cela il faut transformer la macro et ajouter UN NIVEAU de substitution
   */

  /* ----------------------------------------------------------------
   * LA SOLUTION
   * ----------------------------------------------------------------
   * Ajout d'un niveau supplémentaire de substitution
   */

#define TO_STR(X)                                                              \
  WRAPP(X) // RM on redéfinit ici pour l'exercice... mais à ne pas faire

  printf("%s\n", TO_STR(CONS_LIB_NAME(titi))); // avec WRAPP(X) => :-)

  /* On obtient en sortie
   *
   * libtiti.a
   *
   * On observe en sortie l'évaluation de CONS_LIB_NAME(titi), ce que l'on
   * souhaitait
   */

  return 0;
}
```

- [doali main.c](https://github.com/doali/coding/blob/master/c/coding/macro/trick-expanding/main.c)

## Biblio

- [gnu](https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html)
