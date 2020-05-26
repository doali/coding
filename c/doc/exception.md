# Exception

_Pas de mécanisme d'exception en C._ \
_La gestion des erreurs est basée sur des codes retour des fonctions._

## `<errno.h>`

```text
Le langage C fournit un en-tête spécialisé pour la gestion des erreurs : <errno.h>. Cet en-tête déclare notamment une variable globale errno, et un certain nombre de codes d'erreur, qui permettent aux fonctions de la bibliothèque standard de reporter précisément la cause d'une erreur.
```

> Citation de wikibooks

## Important

```c
#include <errno.h>

errno = 0;
```

- Mettre errno à 0 ;
- Appeler la fonction (de la bibliothèque standard) que l'on souhaite ;
- Vérifier si elle a échoué ;
    - Si c'est le cas : la valeur de errno est disponible pour traiter l'erreur ;
    - Sinon : procéder à la suite du traitement.

> Citation wikibooks

## Geeks for geeks (example)

```c

// C implementation to see how perror() and strerror()
// functions are used to print the error messages.
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main ()
{
    FILE *fp;

    // If a file is opened which does not exist,
    // then it will be an error and corresponding
    // errno value will be set
    fp = fopen(" GeeksForGeeks.txt ", "r");

    // opening a file which does
    // not exist.
    printf("Value of errno: %d\n", errno);
    printf("The error message is : %s\n",
                         strerror(errno));
    perror("Message from perror");

    return 0;
}
```

## Biblio

- [wikibooks](https://fr.wikibooks.org/wiki/Programmation_C/Erreurs)
- [geeksforgeeks](https://www.geeksforgeeks.org/error-handling-c-programs/)
